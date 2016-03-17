#!/bin/bash

TEST_DIR=test/codegen_milestone
EXECUTABLE=./bin/c_codegen

if [ $# -eq 0 ]; then
    for INFILE in ${TEST_DIR}/input/*.c
	do
  		BASENAME=$(basename $INFILE .c);
		OUTFILE=${TEST_DIR}/build/${BASENAME}.s
		cat ${INFILE} | ${EXECUTABLE} > ${OUTFILE}
		#echo $FILENAME	
	done
else
	FILENAME=$1
	INFILE=${TEST_DIR}/input/${FILENAME}.c
	OUTFILE=${TEST_DIR}/build/${FILENAME}.s
	
	cat ${INFILE} | ${EXECUTABLE} > ${OUTFILE}
fi

scp -r -P 2222 ${TEST_DIR} vagrant@127.0.0.1:/home/vagrant/




