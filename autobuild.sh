set -x

rm -rf 'pwd'/build/*
cd 'pwd'build &&
  cmake .. &&
  make#!/bin/bash

# 启用调试模式
set -x

# 清理旧的构建文件
rm -rf $(pwd)/build/*

# 进入构建目录，执行 cmake 和 make
cd $(pwd)/build &&
  cmake .. &&
  make

