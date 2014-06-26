pasm -V3 -y -CPru_Init pruio_init.p
pasm -V3 -y -CPru_Run pruio_run.p
pasm -V3 -y -CPru_Exit pruio_exit.p
fbc -target linux pruio.bas -gen gcc -r
gcc -Wall -c -fPIC -O3 -mtune=cortex-a8 -march=armv7-a -o pruio.o pruio.c -Wno-unused-label -Wno-unused-variable
gcc -shared -o libpruio.so pruio.o
ar cr libpruio.a pruio.o
rm pruio.c
rm pruio.o

# Anybody keen on handling this by cmake? Comments are welcome:
#   Thomas{ dOt ]Freiherr[ At ]gmx[ DoT }net
