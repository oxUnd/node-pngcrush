#ifndef _PNG_COMPRESS_H_
#define _PNG_COMPRESS_H_

#include <node.h>

#define BUFFER_SIZE 1024

class PngCompress : public node::ObjectWrap {
public:
    static v8::Persistent<v8::FunctionTemplate> constructor;
    static void Init(v8::Handle<v8::Object> target);
    static v8::Handle<v8::Value> Compress(const v8::Arguments& args);

protected:
    PngCompress();
    static v8::Handle<v8::Value> New(const v8::Arguments& args);
};

#endif
