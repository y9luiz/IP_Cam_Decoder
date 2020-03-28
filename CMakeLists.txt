#
#  Author: Luiz Felipe Maciel Correia
#  E-mail: y9luiz@hotmail.com
#  github: y9luiz
#  facebook: https://www.facebook.com/luizfelipe.macielcorreia.5
#  linkedin: https://www.linkedin.com/in/luiz-correia-78a346168

cmake_minimum_required(VERSION 3.5)

project(decoder_ffmpeg_qt LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

list(APPEND CMAKE_FIND_ROOT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/decoder")

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Decoder REQUIRED)


if(ANDROID)
  add_library(decoder_ffmpeg_qt SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
  )
else()
  add_executable(decoder_ffmpeg_qt
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
  )
endif()
target_include_directories(decoder_ffmpeg_qt PUBLIC ${DECODER_INCLUDE_DIRS})
target_link_libraries(decoder_ffmpeg_qt PRIVATE Qt5::Widgets ${DECODER_LIBRARIES})
