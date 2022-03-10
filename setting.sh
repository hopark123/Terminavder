#!/bin/bash

read -e -p "SDL2 include path: " INCLUDE
read -e -p "SDL2 lib path: " LIB
cp -a $INCLUDE/SDL2 ./engine/include/
cp -a $LIB ./lib

