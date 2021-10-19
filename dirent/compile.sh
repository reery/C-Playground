#!/bin/bash
clang -c -o file_mover.o file_mover.c
clang -c -o main.o main.c
clang -o a.out file_mover.o main.o
rm main.o
rm file_mover.o
