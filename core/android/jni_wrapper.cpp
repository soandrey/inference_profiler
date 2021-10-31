#include <jni.h>
#include <string>
#include <jni.h>

#include "torch_inferencer.hpp"

extern "C" JNIEXPORT jstring JNICALL Java_com_example_inferencebenchmark_MainActivity_stringFromJNI(JNIEnv *env, jobject thiz) {
    TorchInferencer torch_inference;
    std::string hello = torch_inference.say_hello();
    return env->NewStringUTF(hello.c_str());
}
