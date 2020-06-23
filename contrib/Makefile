CMOCKA_BUILD_DIR=cmocka/build
INSTALL_PREFIX=../../../build

build-cmoka:
	rm -rf ${CMOCKA_BUILD_DIR}
	mkdir -p ${CMOCKA_BUILD_DIR}
	cd ${CMOCKA_BUILD_DIR} && cmake -DCMAKE_INSTALL_PREFIX=${INSTALL_PREFIX} .. && make install
