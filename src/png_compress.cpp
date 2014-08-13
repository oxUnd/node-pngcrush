#include "pngcrush/png.h"
#include "pngcrush/pngcrush.h"
#include "png_compress.h"
#include <stdlib.h>
#include <string.h>
#include <node_buffer.h>

using namespace v8;
using namespace node;

Persistent<FunctionTemplate> PngCompress::constructor;

int parseArgv(char *args, char *argv[], int p_size) {
    int i, len = (int)strlen(args), k = 0, argc = 0, is_new = 0;
    char *buf = (char *) malloc (p_size);
    memset(buf, '\0', p_size);
    
    for (i = 0; i < len + 1; i++) {
        if (args[i] != ' ' && i < len) {
            if (k < p_size) {
                buf[k++] = args[i];
                is_new = 1;
            }
        } else {
            if (is_new == 1) {
                strncpy(argv[argc], buf, k);
                memset(buf, '\0', k); //reset
                k = 0; //reset
                argc++;
                is_new = 0;
            }
        }
    }
    
    free(buf);
    
    return argc;
}

void PngCompress::Init(Handle<Object> exports) {
    HandleScope scope;
    
    Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
    Local<String> name = String::NewSymbol("PngCompress");

    constructor = Persistent<FunctionTemplate>::New(tpl);
    // ObjectWrap uses the first internal field to store the wrapped pointer.
    constructor->InstanceTemplate()->SetInternalFieldCount(1);
    constructor->SetClassName(name);

    // Add all prototype methods, getters and setters here.
    NODE_SET_PROTOTYPE_METHOD(constructor, "compress", Compress);

    // This has to be last, otherwise the properties won't show up on the
    // object in JavaScript.
    exports->Set(name, constructor->GetFunction());
}

PngCompress::PngCompress():ObjectWrap() {
}

Handle<Value> PngCompress::New(const Arguments& args) {
    HandleScope scope;

    if (!args.IsConstructCall()) {
        return ThrowException(Exception::TypeError(
            String::New("Use the new operator to create instances of this object."))
        );
    }

      // Creates a new instance object of this type and wraps it.
    PngCompress* obj = new PngCompress();
    
    //PngCompress::in_stream = (png_bytep) Buffer::Data(args[0]->ToObject());
    //PngCompress::in_length = Buffer::Length(args[0]->ToObject());
    //PngCompress::opt = args[1]->ToString();
    //PngCompress::callback = Local<Function>::Cast(args[2]);

    obj->Wrap(args.This());

    return args.This();
}


Handle<Value> PngCompress::Compress(const Arguments& args) {
    HandleScope scope;

    if (args.Length() != 3) {
        return ThrowException(Exception::TypeError(
                String::New("Invalid argument, Need three arguments!")
            )
        );
    }

    if (!Buffer::HasInstance(args[0])) {
        return ThrowException(Exception::TypeError(
                String::New("First argument must be a buffer.")
            )
        );
    }

    if (!args[2]->IsFunction()) {
        return ThrowException(Exception::TypeError(
                String::New("Third argument must be a callback function.")
            )
        );
    }

    png_bytep in_stream = (png_bytep) Buffer::Data(args[0]->ToObject());
    unsigned in_length = Buffer::Length(args[0]->ToObject());
    Local<String> opt = args[1]->ToString();
    Local<Function> callback = Local<Function>::Cast(args[2]);

    Buffer *buffer;
    int i;
    char *argv[32];
    int argc;

    char str_buffer[BUFFER_SIZE];
    char buf[BUFFER_SIZE];
    memset(str_buffer, '\0', BUFFER_SIZE);
    memset(buf, '\0', BUFFER_SIZE);

    opt->WriteUtf8(str_buffer);
    strcpy(buf, "pngcrush ");

    for (i = 0; i < 32; i++) {
        argv[i] = (char *)malloc(33);
    }

    strcat(buf, str_buffer);

    argc = parseArgv(buf, argv, 32);

    user_png_structp out_buffer;
    user_png_structp in_buffer;
    in_buffer = (user_png_structp)malloc(sizeof(user_png_struct));
    if (in_buffer == NULL) {
        return ThrowException(Exception::TypeError(
                String::New("malloc fail!")
            )
        );
    }
    
    memset(in_buffer, '\0', sizeof(user_png_struct));

    in_buffer->data = in_stream;
    in_buffer->length = in_length;
    in_buffer->current = 0;

    out_buffer = png_reduce(in_buffer, argc, argv);

    buffer = Buffer::New((char *)out_buffer->data, out_buffer->length);

    free(in_buffer);
    free(out_buffer);

    for (i = 0; i < 32; i++) {
        free(argv[i]);
    }

    return scope.Close(
        buffer->handle_
    );
}

void RegisterModule(Handle<Object> exports) {
    PngCompress::Init(exports);
}

NODE_MODULE(png_compress, RegisterModule);
