#! /bin/sh

cmake -DGLFW_BUILD_WAYLAND=OFF -DGLFW_BUILD_X11=OFF -DGLFW_BUILD_DOCS=OFF -S . -B build
