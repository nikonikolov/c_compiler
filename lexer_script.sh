#!/bin/bash

TEST_DIR=test/lexer_milestone
#EXECUTABLE=./bin/c_lexer
EXECUTABLE=./bin/lexer_test

if [ $# -eq 0 ]; then
    for INFILE in ${TEST_DIR}/*.run.in
	do
		OUTFILE=${INFILE/.in/.out}
		cat ${INFILE} | ${EXECUTABLE} > ${OUTFILE}
		#echo $FILENAME	
	done
else
	FILENAME=$1
	FILEPATH=test/lexer_milestone/${FILENAME}
	INFILE=${FILEPATH}.run.in
	OUTFILE=${FILEPATH}.run.out
	
	cat ${INFILE} | ${EXECUTABLE} > ${OUTFILE}
fi



#rm -f ${OUTFILE}

#cat ${INFILE} | ${EXECUTABLE} > ${OUTFILE}


