#!/bin/bash

OUTDIR=test/parser_milestone
INDIR=test/codegen_milestone/input
EXECUTABLE=./bin/c_parser
#EXECUTABLE=./bin/lexer_test

if [ $# -eq 0 ]; then
    for INFILE in ${INDIR}/*.c
	do
		OUTFILE=${OUTDIR}/${INFILE/.c/.run.out}
		cat ${INFILE} | ${EXECUTABLE} > ${OUTFILE}
		#echo $FILENAME	
	done
else
	FILENAME=$1
	INFILE=${INDIR}/${FILENAME}.c
	OUTFILE=${OUTDIR}/${FILENAME}.run.out
	
	cat ${INFILE} | ${EXECUTABLE} > ${OUTFILE}
fi






