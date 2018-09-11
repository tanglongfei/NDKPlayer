//
// Created by Administrator on 2018/9/10.
//

#ifndef NDKPLAYER_JABACALLHELPER_H
#define NDKPLAYER_JABACALLHELPER_H


#include <jni.h>

class JabaCallHelper {
public:
    JabaCallHelper(JavaVM *vm, JNIEnv *env, jobject instance);

    ~JabaCallHelper();

//thread:标记是否属于主线程
    void onError(int thread, int errorCode);
    void onPrepare(int thread);
private:
    JavaVM *vm;
    JNIEnv *env;
    jobject instance;
    jclass clazz;
    jmethodID onErrorId;
    jmethodID onPrepareId;
};


#endif //NDKPLAYER_JABACALLHELPER_H
