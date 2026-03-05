#!/bin/bash
PS4='$ '
set -x
make clean
make y1.o
make y1.o
make
