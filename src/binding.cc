#include <node.h>
#include <node_buffer.h>
#include "PCCompress.h"

extern "C" {
napi_value Init(napi_env env, napi_value exports) {
  return PCCompress::Init(env, exports);
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init);
}