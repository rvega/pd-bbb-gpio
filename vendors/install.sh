#! /bin/sh

# Install free basic compiler.
cd bbb_fbc-0.0.2
cp usr/local/bin/fbc /usr/local/bin/
cp -R usr/local/lib/freebasic /usr/local/lib/

# Compile libfb. Makefile has been changed to use -fPIC compiler flag 
cd ../FreeBASIC-0.90.0-source
   # make rtlib
mkdir -p /usr/local/include/freebasic
cp lib/freebasic/* /usr/local/lib/freebasic

# Install PRUSS driver freebasic kit.
cd ../FB_prussdrv-0.0
cp bin/libprussdrv.* /usr/local/lib
ldconfig
mkdir -p /usr/local/include/freebasic/BBB
cp include/* /usr/local/include/freebasic/BBB
cp bin/pasm /usr/local/bin
cp bin/PRUSSDRV-00A0.dtbo /lib/firmware
apt-get install am335x-pru-package

# Install libpruio
cd ../libpruio-0.0.2/libpruio/src/c_wrapper
cp libpruio.so /usr/local/lib
cp libpruio.a /usr/local/lib
ldconfig
cd ../pruio/
cp pruio.bi /usr/local/include/freebasic/BBB
cp pruio.hp /usr/local/include/freebasic/BBB
cp pruio_pins.bi /usr/local/include/freebasic/BBB
