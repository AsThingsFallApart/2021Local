#!/bin/bash

# generateOutput.sh
# assumptions:
# 1. this script is executed in a directory containing a binary
# 2. this script is executed in a directory containing a set of input files

# TODO:
# find a way to dynamically reference binary and input files
# possibleSolution: keep script in directory above source file and data files
# then have the script cd into source file directory, compile the binary into centralized directory
# also have the script cd into corresponding input file directory and copy all input files
# into same centralized directory
# all that needs to be done is pass the source file name as a parameter to script

# execute the binary on all input files
# to generate a corresponding set of output files
for file in *.in
do
	./rain <"$file"> "${file}.out"
	echo "running rain binary on $file..."
done

# use "rename" util (not in default ubuntu installation)
# to change file extension from '.in.out' to '.out'
# the rename util uses a "perl experession" to specifiy files to rename
# the '-v' option is used to print changes to standard output stream
rename -v 's/in.out/out/' *.in.out

# make a directory called 'output'
# in the directory directly above current directory
mkdir -v ../output

# move all generated output files to 'output' directory
for file in *.out
do
	mv -v "$file" ../output
done
