#!/bin/sh

echo "Cleaning directory"
rm test_my_modules  
echo "Cleaning directory: Done"
echo

echo "Building test binary"
gcc -I ./Unity/src/ my_module_add.c my_module_mul.c test_my_modules.c ./Unity/src/unity.c -o test_my_modules
echo "Building test binary: Done"
echo

echo "Running test binary: test_my_modules"
echo  
./test_my_modules
