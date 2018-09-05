#include <jni.h>
#include <string>

extern "C"{
#include <libavcodec/avcodec.h>
}

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_pineteree_ndkplayer_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    av_version_info();
    return env->NewStringUTF(av_version_info());
}
