#!/bin/bash

TEST_DIR=test/codegen_milestone
EXECUTABLE=./bin/c_codegen

if [ $# -eq 0 ]; then
    for INFILE in ${TEST_DIR}/*.c
	do
		OUTFILE=${INFILE/.c/.s}
		ERRFILE=${INFILE/.c/.err}
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

scp -r -P 2222 ${TEST_DIR} vagrant@127.0.0.1:/home/vagrant/




