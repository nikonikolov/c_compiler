#!/bin/bash

COMPILER_MIPS=mips-linux-gnu-gcc
EMULATOR_MIPS=qemu-mips
#TEST_DIR=test/codegen_milestone
TEST_DIR=.
EXECUTABLE=./bin/c_codegen

GCC_BUILD=${TEST_DIR}/tmpexec

if [ $# -eq 0 ]; then
    for INFILE in ${TEST_DIR}/*.c
	do
		ASSEMBLY=${INFILE/.c/.s}
		gcc
		cat ${INFILE} | ${EXECUTABLE} > ${OUTFILE}
		#echo $FILENAME	
	done
else
	FILENAME=$1
	FILEPATH=${TEST_DIR}/${FILENAME}
	INFILE=${FILEPATH}.c
	OUTFILE=${FILEPATH}.s
	
	cat ${INFILE} | ${EXECUTABLE} > ${OUTFILE}
fi

scp -P 2222 ${TEST_DIR}/*.s vagrant@127.0.0.1:/home/vagrant/tests/




