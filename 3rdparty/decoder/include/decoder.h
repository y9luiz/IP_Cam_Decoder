#ifndef DECODER_H
#define DECODER_H

#include "decoder_global.h"

#include <QString>
extern "C"{

    #include <libavformat/avformat.h>
    #include <libavcodec/avcodec.h>
    #include <libswscale/swscale.h>

}
class DECODER_EXPORT Decoder
{
public:
    Decoder();
    ~Decoder();

    void set_ip(QString ip);
    void init();
    bool get_frame();
    void clear();
    AVFrame * frame;
    AVFrame * rgb_frame;

private:
    AVFormatContext * fmt_context;
    AVCodecContext * ccontext;

    int * rgb_linesize;
    int * yuv_linesize;

    QString ip;

    int ivstream;

    SwsContext * img_convert_ctx;
    AVStream* stream;

    void convertYUV2RGB();

};

#endif // DECODER_H
