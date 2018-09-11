//
// Created by Administrator on 2018/9/7.
//

#ifndef NDKPLAYER_TLFFFMPEG_H
#define NDKPLAYER_TLFFFMPEG_H


#include "JabaCallHelper.h"
#include "AudioChannel.h"
#include "VideoChannel.h"

extern "C" {
#include <libavformat/avformat.h>
};

class TLFFFmpeg {
public:

    TLFFFmpeg(JabaCallHelper *callHelper,const char *dataSource);

    ~TLFFFmpeg();

    void prepare();

    void _prepare();

private:
    char *dataSource;
    //线程id
    pthread_t pid;
    AVFormatContext *formatContext;
    JabaCallHelper *callHelper;
    AudioChannel *audioChannel;
    VideoChannel *videoChannel;
};

#endif //NDKPLAYER_TLFFFMPEG_H
