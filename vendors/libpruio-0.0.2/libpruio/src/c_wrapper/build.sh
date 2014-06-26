fbc -target linux pruio_c_wrapper.bas -gen gcc -r
gcc -Wall -c -fPIC -O3 -mtune=cortex-a8 -march=armv7-a -o pruio.o pruio_c_wrapper.c -Wno-unused-label -Wno-unused-variable
gcc -shared -o libpruio.so pruio.o
ar cr libpruio.a pruio.o
rm pruio_c_wrapper.c
rm pruio.o

# Anybody keen on handling this by cmake? Comments are welcome:
#   Thomas{ dOt ]Freiherr[ At ]gmx[ DoT }net
