CC=gcc
INCLUDE_DIR=include
BUILD_DIR=build
SRC_DIR=src/flex2d

all: compile

compile: vector contrib
	${CC} -shared -o ${BUILD_DIR}/vector.so -lm

vector:
	${CC} -c -o ${BUILD_DIR}/vector.o ${SRC_DIR}/vector.c -I ${INCLUDE_DIR} -lm

contrib:
	cd contrib && $(MAKE)
	
