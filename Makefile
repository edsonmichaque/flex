CC=gcc
INCLUDE_DIR=include
BUILD_DIR=build
SRC_DIR=src/flex2d
INCLUDE_TEST=build/include
CMOCKA_LIBRARY_DIR=build/lib64
VECTOR_LIBRARY_DIR=build
LD_LIBRARY_PATH=${VECTOR_LIBRARY_DIR}:${CMOCKA_LIBRARY_DIR}
all: compile

compile: vector contrib
	${CC} -shared -o ${BUILD_DIR}/libvector.so ${BUILD_DIR}/vector.o -lm

vector:
	${CC} -c -fPIC -o ${BUILD_DIR}/vector.o ${SRC_DIR}/vector.c -I ${INCLUDE_DIR} -lm

contrib:
	cd contrib && $(MAKE)

compile-test: test/unit/flex2d/test_vector_new.c
	${CC} -o ${BUILD_DIR}/test \
		test/unit/flex2d/test_vector_new.c \
		-I ${INCLUDE_TEST} \
		-I ${INCLUDE_DIR} \
		-L ${CMOCKA_LIBRARY_DIR} \
		-lcmocka \
		-L ${VECTOR_LIBRARY_DIR} \
		-lvector \
		-lm 

test: compile-test
	LD_LIBRARY_PATH=${LD_LIBRARY_PATH} ${BUILD_DIR}/test

clean:
	rm -rf build/*.{o,so}

