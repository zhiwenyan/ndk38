#include <jni.h>
#include <string>
#include <android/log.h>
#include "ArrayStack.hpp"
#include "LinkedStack.hpp"


#define TAG "MAIN_TAG"


//递归
//1、肯定有递归结束的情况
//2、求解的思路能够拆分成很多小的部分，每个小的部分求解的思路一致
//3、大的部分求解依赖小的部分的解决

int sum(int n) {
    if (n == 1) {
        return n;
    }
    return n * sum(n - 1);
}

extern "C" JNIEXPORT jstring

JNICALL
Java_com_steven_ndk38_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    int sum1 = sum(10);

    __android_log_print(ANDROID_LOG_ERROR, TAG, "%d", sum1);


    ArrayStack<int> arrayStack;

    for (int i = 0; i < 10; ++i) {
        arrayStack.push(i);
    }
    while (!arrayStack.isEmpty()) {
        __android_log_print(ANDROID_LOG_ERROR, TAG, "%d", arrayStack.pop());

    }
    LinkedStack<int> linkedStack;
    for (int i = 0; i < 10; ++i) {
        linkedStack.push(i);

    }
  //  __android_log_print(ANDROID_LOG_ERROR, TAG, "%d", linkedStack.pop());


    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
