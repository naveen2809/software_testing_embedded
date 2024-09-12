#!/bin/sh

echo "Cleaning directory"
rm test_my_module_add
rm test_my_module_mul  
echo "Cleaning directory: Done"
echo

echo "Building test binaries"
gcc -I ./Unity/src/ my_module_add.c test_my_module_add.c ./Unity/src/unity.c -o test_my_module_add
gcc -I ./Unity/src/ my_module_mul.c test_my_module_mul.c ./Unity/src/unity.c -o test_my_module_mul
echo "Building test binaries: Done"
echo

echo "Running test binaries"
echo "Test Binary: test_my_module_add"
echo  
./test_my_module_add
echo 
echo "Test Binary: test_my_module_mul"
echo
./test_my_module_mul