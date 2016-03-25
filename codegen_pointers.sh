#!/bin/bash

TEST_DIR=test/codegen_milestone
EXECUTABLE=./bin/c_codegen
OUTDIR=${TEST_DIR}/build_pointers
INDIR=${TEST_DIR}/input_pointers
PREP_DIR=${TEST_DIR}/preprocessed_pointers
FNCALL=${TEST_DIR}/fncall_pointers.c

PREPROCESSOR=g++

if [ $# -eq 0 ]; then
	for INFILE in ${INDIR}/*.c
	do
		echo "INPUT FILE: " ${INFILE}
	  		BASENAME=$(basename $INFILE .c);
		PREP_FILE=${PREP_DIR}/${BASENAME}.c
		OUTFILE=${OUTDIR}/${BASENAME}.s
		# Preprocess the files
		${PREPROCESSOR} ${FNCALL} ${INFILE} -E > ${PREP_FILE}
		# Run your compiler
		cat ${PREP_FILE} | ${EXECUTABLE} $1 > ${OUTFILE}
	done
fi

if [ $# -eq 1 ]; then
	# Command line argument for the program
	if [[ $1 == -* ]]; then
	    for INFILE in ${INDIR}/*.c
		do
			echo "INPUT FILE: " ${INFILE}
	  		BASENAME=$(basename $INFILE .c);
			PREP_FILE=${PREP_DIR}/${BASENAME}.c
			OUTFILE=${OUTDIR}/${BASENAME}.s
			# Preprocess the files
			${PREPROCESSOR} ${FNCALL} ${INFILE} -E > ${PREP_FILE}
			# Run your compiler
			cat ${PREP_FILE} | ${EXECUTABLE} $1 > ${OUTFILE}
		done
	# Argument is filename
	else
		FILENAME=$1
		INFILE=${INDIR}/${FILENAME}.c
		PREP_FILE=${PREP_DIR}/${FILENAME}.c
		OUTFILE=${OUTDIR}/${FILENAME}.s
		
		# Preprocess the files
		${PREPROCESSOR} ${FNCALL} ${INFILE} -E > ${PREP_FILE}
		# Run your compiler	
		cat ${PREP_FILE} | ${EXECUTABLE} > ${OUTFILE}
	fi
fi

if [ $# -eq 2 ]; then
	FILENAME=$1
	INFILE=${INDIR}/${FILENAME}.c
	PREP_FILE=${PREP_DIR}/${FILENAME}.c
	OUTFILE=${OUTDIR}/${FILENAME}.s
	
	# Preprocess the files
	${PREPROCESSOR} ${FNCALL} ${INFILE} -E > ${PREP_FILE}
	# Run your compiler	
	cat ${PREP_FILE} | ${EXECUTABLE} $2 > ${OUTFILE}
fi

scp -r -P 2222 ${TEST_DIR} vagrant@127.0.0.1:/home/vagrant/




