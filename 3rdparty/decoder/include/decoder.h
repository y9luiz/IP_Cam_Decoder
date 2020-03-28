/*
 *
 *  Author: Luiz Felipe Maciel Correia
 *  E-mail: y9luiz@hotmail.com
 *  github: y9luiz
 *  facebook: https://www.facebook.com/luizfelipe.macielcorreia.5
 *  linkedin: https://www.linkedin.com/in/luiz-correia-78a346168
 */

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
    void set_ip(QString ip);
    void init();
    bool get_frame();
    void clear();
private:
    AVFormatContext * fmt_context;
    AVCodecContext * ccontext;

    int * rgb_linesize;
    int * yuv_linesize;

    QString ip;

    int ivstream;

    SwsContext * img_convert_ctx;
    AVStream* stream;

    AVFrame * frame;
    void convertYUV2RGB();

};

#endif // DECODER_H
