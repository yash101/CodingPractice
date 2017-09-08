#!/bin/bash

CC=`which gcc`
CXX=`which g++`
BUILDDIR=`mktemp -d`
echo "Building code in ${BUILDDIR}"

for f in *.c
do
	if [ -f $f ]; then
		echo "Compiling ${f} into ${BUILDDIR}/${f}.o"
		gcc -c -o ${BUILDDIR}/${f}.o $f -Wall -O0 -ggdb
	fi
done

for f in *.cpp *.cxx *.cc *.c++
do
	if [ -f $f ]; then
		echo "Compiling ${f} into ${BUILDDIR}/${f}.o"
		gcc -c -o ${BUILDDIR}/${f}.o $f -Wall -O0 -ggdb
	fi
done

if [ -d "binaries" ]; then
	rm -r binaries
fi

mkdir binaries

for o in ${BUILDDIR}/*.o
do
	if [ -f $o ]; then
		echo "Building and linking executable, ${o} -> binaries/`basename ${o}`"
		name=`basename ${o}`
		gcc $o -o binaries/${name}
	fi
done

echo "Deleting temp build directory"
rm -r ${BUILDDIR}

