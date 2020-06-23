CC=gcc
INCLUDE_DIR=include
BUILD_DIR=build
SRC_DIR=src/flex2d

all: vector

compile: vector

vector:
	${CC} -o ${BUILD_DIR}/vector.o ${SRC_DIR}/flex2d/vector.c
