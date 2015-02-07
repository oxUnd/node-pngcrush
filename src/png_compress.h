#ifndef _PNG_COMPRESS_H_
#define _PNG_COMPRESS_H_

#include <nan.h>

#define BUFFER_SIZE 1024

class PngCompress : public node::ObjectWrap {
public:
    static v8::Persistent<v8::FunctionTemplate> constructor;
    static void Init(v8::Handle<v8::Object> exports);
    static NAN_METHOD(Compress);

protected:
    PngCompress();
    static NAN_METHOD(New);
};

#endif
