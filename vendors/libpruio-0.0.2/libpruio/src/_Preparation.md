Preparation {#ChaPreparation}
===========

When using libpruio you neither need device tree compilers nor overlays
for analog or digital pin configurations. All setup gets done in single
source inside your program, controlling the driver that is running on a
co-processor (PRUSS). All you have to ensure to load the kernel driver
for the PRU subsystem and start it once at system startup.

\note All following installation commands are to be executed with
      system administrator privilegues on the Beaglebone hardware with
      a Debian based LINUX operating system.

Once the library is installed, selected users can use it without the
need of admin privilegues.


Dependencies  {#SubPreDeps}
============

libpruio is based on *libprussdrv* from the package
[am335x_pru_package](https://github.com/beagleboard/am335x_pru_package).
You've to download and install the [FB prussdrv Kit
(de)](http://www.freebasic-portal.de//downloads/fb-on-arm/fb-prussdrv-kit-bbb-324.html)
first. Find English installation instructions in
[this link at the bottom of the German page](http://www.freebasic.net/forum/viewtopic.php?f=14&t=22461#p197061).

To compile changes in the examples or in the library source code, you
need an ARM version of the FreeBASIC compiler. The binaries in this
package were compiled by [BBB-FBC
(de)](http://www.freebasic-portal.de/downloads/fb-on-arm/bbb-fbc-fbc-fuer-beaglebone-black-283.html),
an english discussion on this project should be available at [this
site](http://www.freebasic.net/forum/viewtopic.php?f=5&t=21372)
(contact admins if the link is still down).


System preparation  {#SubPreSystem}
==================

To execute software based on libpruio driver you have to ensure that

-# the kernel driver *uio_pruss* is loaded.
-# the PRU subsystem is powered on,
-# the user has read / write privilegues to the `/dev/uio5` system interrupt

The first and second preconditions can be reached at once. Either activate
one of the prepared operating systems device tree overlays. Ie. execute

~~~{.sh}
sudo echo BB-BONE-PRU-01 > /sys/devices/bone_capemgr.9/slots
~~~

Or you use the minimal overlay provided in the above mentioned FB
prussdrv Kit package, which needs to get installed in the right folder
(/lib/firmware), first. Then execute

~~~{.sh}
sudo echo PRUSSDRV > /sys/devices/bone_capemgr.9/slots`
~~~

Both device tree overlays start the PRUSS and also load the kernel
driver. The kernel driver allocates external memory for the PRUSS,
which is a default of 256 kB. (See section \ref SubERam on how to
customize this.)

Item 3 can either be reached by running the software as user `root`.
But the prefered method should be installing privilegues for the
related users:

- create a new user group (ie `addgroup pruio`)
- adapt this group to the interrupt device (ie `chgrp pruio /dev/uio5`)
- activate read / write privilegues for this group (ie `chmod g+rw /dev/uio5`)
- and make yourself (and all related users) a member of this group

\note Enabling the PRU subsystem may be a safety risk. A virus running
      at the PRUSS can access each device register or memory area. The
      kernel running on the host cannot protect the system.


Library preparation  {#SecPrePruio}
===================

This package contains a pre-compiled version of the libpruio binaries
in the folder src/c_wrapper. It's the universal (all-in) version,
including the C wrapper functions. This section is about the
installation instructions.


FreeBASIC  {#SubPreFB}
---------

To install libpruio on your system and use it in your FreeBASIC code,
you have to copy the binaries to a folder where the linker can find
them. Futhermore copy the headers to a propper place where the compiler
can find them. Starting from the basis folder of the unpacked libpruio
package and execute:

~~~{.sh}
sudo su
cd src/c_wrapper/
cp libpruio.so /usr/local/lib
cp libpruio.a /usr/local/lib
ldconfig
cd ../pruio/
mkdir /usr/local/include/freebasic/BBB
cp pruio.bi /usr/local/include/freebasic/BBB
cp pruio.hp /usr/local/include/freebasic/BBB
cp pruio_pins.bi /usr/local/include/freebasic/BBB
exit
~~~

\note For testing only, you can skip the header files (*.bi and *.hp)
      part. Just execute until ldconfig and then exit.


C Compiler  {#SubPreC}
----------

The author isn't a C expert and doesn't know if if this is a propper
insatallation. To compile the C examples the following was done
(starting from the basis folder of the unpacked libpruio package):

~~~{.sh}
sudo su
cd src/c_wrapper/
cp libpruio.so /usr/local/lib
cp libpruio.a /usr/local/lib
ldconfig
cp pruio.h /usr/local/include
cp pruio_c_wrapper.h /usr/local/include
cp pruio_pins.h /usr/local/include
cp ../pruio/pruio.hp /usr/local/include
exit
~~~

\note For testing only, you can skip the header files (*.h and *.hp)
      part. Just execute until ldconfig and then exit.
