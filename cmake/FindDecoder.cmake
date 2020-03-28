#
#  Author: Luiz Felipe Maciel Correia
#  E-mail: y9luiz@hotmail.com
#  github: y9luiz
#  facebook: https://www.facebook.com/luizfelipe.macielcorreia.5
#  linkedin: https://www.linkedin.com/in/luiz-correia-78a346168

find_path(DECODER_INCLUDE_DIRS NAMES decoder.h PATH_SUFFIXES decoder)


find_library(DECODER_LIBRARIES NAMES decoder)

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(decoder REQUIRED_VARS DECODER_INCLUDE_DIRS DECODER_LIBRARIES)

mark_as_advanced(DECODER_INCLUDE_DIRS DECODER_LIBRARIES)
message("helping... " ${DECODER_LIBRARIES})
