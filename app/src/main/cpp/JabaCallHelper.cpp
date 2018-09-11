//
// Created by Administrator on 2018/9/5.
//

#include <jni.h>
#include "JabaCallHelper.h"
#include "macro.h"

JabaCallHelper::JabaCallHelper(JavaVM *vm, JNIEnv *env, jobject instance) {
    this->vm = vm;
    //如果在主线程 回调
    this->env = env;
    // 一旦涉及到jobject 跨方法 跨线程 就需要创建全局引用
    this->instance = env->NewGlobalRef(instance);

    jclass  clazz = env->GetObjectClass(instance);
    //绑定对应java中的方法
    onErrorId = env->GetMethodID(clazz,"onError","(I)V");
    onPrepareId = env->GetMethodID(clazz,"onPrepare","()V");
}

JabaCallHelper::~JabaCallHelper() {
    env->DeleteGlobalRef(instance);
}

void JabaCallHelper::onError(int thread,int error){
    //主线程
    if (thread == THREAD_MAIN){
        //调用java中的方法
        env->CallVoidMethod(instance,onErrorId,error);
    } else{
        //子线程
        JNIEnv *env;
        //获得属于我这一个线程的jnienv
        vm->AttachCurrentThread(&env,0);
        //调用java中的方法
        env->CallVoidMethod(instance,onErrorId,error);
        vm->DetachCurrentThread();
    }
}

void JabaCallHelper::onPrepare(int thread) {
    if (thread == THREAD_MAIN){
        env->CallVoidMethod(instance,onPrepareId);
    } else{
        //子线程
        JNIEnv *env;
        //获得属于我这一个线程的jnienv
        vm->AttachCurrentThread(&env,0);
        env->CallVoidMethod(instance,onPrepareId);
        vm->DetachCurrentThread();
    }
}