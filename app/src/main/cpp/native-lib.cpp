#include <jni.h>
#include "TLFFFmpeg.h"
#include <string>

TLFFFmpeg *tlffFmpeg = 0;

JavaVM *javaVM = 0;

int JNI_OnLoad(JavaVM *vm, void *r) {

    javaVM = vm;
    return JNI_VERSION_1_6;
}


extern "C"
JNIEXPORT void JNICALL
Java_com_pineteree_ndkplayer_TLFPlayer_native_1prepare(JNIEnv *env, jobject instance,
                                                       jstring dataSource_) {
    const char *dataSource = env->GetStringUTFChars(dataSource_, 0);
    JabaCallHelper *jabaCallHelper = new JabaCallHelper(javaVM, env, instance);
    //创建播放器
    tlffFmpeg = new TLFFFmpeg(jabaCallHelper, dataSource);
    tlffFmpeg->prepare();
    env->ReleaseStringUTFChars(dataSource_, dataSource);
}


