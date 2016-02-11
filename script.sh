#!/bin/bash

if [ $# -eq 0 ]; then
    FILENAME=simple_test
else
	FILENAME=$1
fi

FILEPATH=test/${FILENAME}
INFILE=${FILEPATH}.prep
EXECUTABLE=./bin/c_lexer
OUTFILE=${FILEPATH}.output

cat ${INFILE} | ${EXECUTABLE} > ${OUTFILE}

