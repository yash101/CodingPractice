#!/bin/bash

CC=`which gcc`
CXX=`which g++`
BUILDDIR=`mktemp -d`
echo "Building code in ${BUILDDIR}"

for f in *.c
do
	if [ -f $f ]; then
		if [[ "$f" =~ "*.nocompile.*" ]]; then
			echo "Not compiling $f"
		else
			echo "Compiling ${f} into ${BUILDDIR}/${f}.o"
			gcc -c -o ${BUILDDIR}/${f}.o $f -Wall -O0 -ggdb
		fi
	fi
done

for f in *.cpp *.cxx *.cc *.c++
do
	if [ -f $f ]; then
		if [[ "$f" =~ "*.nocompile.*" ]]; then
			echo "Not compiling $f"
		else
			echo "Compiling ${f} into ${BUILDDIR}/${f}.o"
			g++ -c -o ${BUILDDIR}/${f}.o $f -Wall -O0 -ggdb
		fi
	fi
done

if [ -d "binaries" ]; then
	rm -r binaries
fi

mkdir binaries

for o in ${BUILDDIR}/*c.o
do
	if [ -f $o ]; then
		if [[ "$o" =~ "*.build.*" ]]; then
			echo "Skipping ${o}"
		else
			echo "Building and linking executable, ${o} -> binaries/`basename ${o}`"
			name=`basename ${o}`
			gcc $o -o binaries/${name}
		fi
	fi
done

for o in ${BUILDDIR}/*cpp.o ${BUILDDIR}/*.cxx.o ${BUILDDIR}/*.cc.o ${BUILDDIR}/*.c++.o
do
	if [ -f $o ]; then
		if [[ "$o" =~ "*.build.*" ]]; then
			echo "Skipping ${o}"
		else
			echo "Building and linking executable, ${o} -> binaries/`basename ${o}`"
			name=`basename ${o}`
			g++ $o -o binaries/${name}
		fi
	fi
done

echo "Deleting temp build directory"
rm -r ${BUILDDIR}

