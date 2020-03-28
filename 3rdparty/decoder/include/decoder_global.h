#ifndef DECODER_GLOBAL_H
#define DECODER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DECODER_LIBRARY)
#  define DECODER_EXPORT Q_DECL_EXPORT
#else
#  define DECODER_EXPORT Q_DECL_IMPORT
#endif

#endif // DECODER_GLOBAL_H
