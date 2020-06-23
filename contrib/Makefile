CMOCKA_BUILD_DIR=cmocka/build
INSTALL_PREFIX=../../../build

build-cmoka:
	rm -rf ${CMOCKA_BUILD_DIR} ${INSTALL_PREFIX}
	mkdir -p ${CMOCKA_BUILD_DIR} ${INSTALL_PREXIF}
	cd ${CMOCKA_BUILD_DIR} && cmake -DCMAKE_INSTALL_PREFIX=${INSTALL_PREFIX} .. && make install
