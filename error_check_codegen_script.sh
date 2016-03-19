#!/bin/bash

TEST_DIR=test/codegen_milestone
EXECUTABLE=./bin/c_codegen
INPUT_DIR=${TEST_DIR}/error_input
OUTPUT_DIR=${TEST_DIR}/error_output

if [ $# -eq 0 ]; then
    for INFILE in ${INPUT_DIR}/*.c
	do
  		echo ${INFILE}
  		BASENAME=$(basename $INFILE .c);
		OUTFILE=${OUTPUT_DIR}/${BASENAME}.s
		cat ${INFILE} | ${EXECUTABLE} > ${OUTFILE}
		#echo $FILENAME	
	done
else
	FILENAME=$1
	INFILE=${INPUT_DIR}/${FILENAME}.c
	OUTFILE=${OUTPUT_DIR}/${FILENAME}.s
	
	cat ${INFILE} | ${EXECUTABLE} > ${OUTFILE}
fi

#scp -r -P 2222 ${TEST_DIR} vagrant@127.0.0.1:/home/vagrant/




