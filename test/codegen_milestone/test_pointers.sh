#!/bin/bash

CODEGEN=../bin/c_codegen
EMULATOR=qemu-mips
MIPS_GCC=mips-linux-gnu-gcc
MAIN=main_fncall_pointers.c
MEDIATOR=fncall_pointers.c
OUTDIR=build_pointers
INDIR=input_pointers
OUTPUTDIR=output_pointers

if [ $# -eq 0 ]; then
  for i in ${INDIR}/*.c; do
    FILENAME=$(basename $i .c);

    echo "FILE: " $FILENAME
    ###################################
    ## Compile everything using gcc to get a reference (native) version

    ${MIPS_GCC} -static ${MAIN} $i ${MEDIATOR} -o ${OUTDIR}/${FILENAME}.gccref
    ${EMULATOR} ${OUTDIR}/${FILENAME}.gccref > ${OUTPUTDIR}/${FILENAME}.reference

    ###################################
    ## Compile the function using your compiler and link it with the main using gcc

    # TODO: C pre-processor?

    # Compile the main and the assembly generated by your compiler
    ${MIPS_GCC} -static ${MAIN} ${OUTDIR}/${FILENAME}.s -o ${OUTDIR}/${FILENAME}
  
    # Run the executable
    ${EMULATOR} ${OUTDIR}/${FILENAME} > ${OUTPUTDIR}/${FILENAME}.got

    ##################################
    ## Compare the outputs
    diff ${OUTPUTDIR}/${FILENAME}.got ${OUTPUTDIR}/${FILENAME}.reference > ${OUTPUTDIR}/${FILENAME}.diff;
    if [[ $? != 0 ]]; then
      echo "${FILENAME}, FAIL, see ${OUTPUTDIR}/${FILENAME}.diff";
    else
      echo "${FILENAME}, pass";
    fi
  done
else
  FILENAME=$1

    ###################################
    ## Compile everything using gcc to get a reference (native) version
    ${MIPS_GCC} -static ${MAIN} ${INDIR}/${FILENAME}.c ${MEDIATOR} -o ${OUTDIR}/${FILENAME}.gccref
    ${EMULATOR} ${OUTDIR}/${FILENAME}.gccref > ${OUTPUTDIR}/${FILENAME}.reference

    ###################################
    ## Compile the function using your compiler and link it with the main using gcc

    # TODO: C pre-processor?

    # Compile the main and the assembly generated by your compiler
    ${MIPS_GCC} -static ${MAIN} ${OUTDIR}/${FILENAME}.s -o ${OUTDIR}/${FILENAME}
  
    # Run the executable
    ${EMULATOR} ${OUTDIR}/${FILENAME} > ${OUTPUTDIR}/${FILENAME}.got

    ##################################
    ## Compare the ${OUTPUTDIR}s
    diff ${OUTPUTDIR}/${FILENAME}.got ${OUTPUTDIR}/${FILENAME}.reference > ${OUTPUTDIR}/${FILENAME}.diff;
    if [[ $? != 0 ]]; then
      echo "${FILENAME}, FAIL, see ${OUTPUTDIR}/${FILENAME}.diff";
    else
      echo "${FILENAME}, pass";
    fi
fi


