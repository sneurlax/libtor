#!/bin/bash

export WORKDIR="$(pwd)/"build
export CACHEDIR="$(pwd)/"cache

export ANDROID_NDK_ZIP=${CACHEDIR}/android-ndk-r20b.zip
export ANDROID_NDK_ROOT=${WORKDIR}/android-ndk-r20b
export ANDROID_NDK_HOME=$ANDROID_NDK_ROOT

export API=21
#r21e also works and was the preferred before

# Only choose one of these, depending on your build machine...
#export TOOLCHAIN=$ANDROID_NDK_HOME/toolchains/llvm/prebuilt/darwin-x86_64
export TOOLCHAIN=$ANDROID_NDK_HOME/toolchains/llvm/prebuilt/linux-x86_64

# Only choose one of these, depending on your device...
#export TARGET=aarch64-linux-android
#export TARGET=armv7a-linux-androideabi
#export TARGET=i686-linux-android
export TARGET=x86_64-linux-android

ARCH=linux-x86_64
export AR=$TOOLCHAIN/bin/llvm-ar
export CC=$TOOLCHAIN/bin/$TARGET$API-clang
export AS=$CC
export CXX=$TOOLCHAIN/bin/$TARGET$API-clang++
export LD=$TOOLCHAIN/bin/ld
export RANLIB=$TOOLCHAIN/bin/x86_64-linux-android-ranlib # TODO change based on arch
export STRIP=$TOOLCHAIN/bin/llvm-strip

export PKG_CONFIG_PATH=$ANDROID_NDK_HOME/prebuilt/$ARCH/lib/pkgconfig
export PKG_CONFIG_SYSROOT_DIR=$ANDROID_NDK_HOME/prebuilt/$ARCH/lib/pkgconfig
