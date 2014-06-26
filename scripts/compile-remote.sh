#!/bin/sh

rsync -avu ./ root@192.168.7.2:~/pd-beaglebone_gpio
ssh root@192.168.7.2 "cd ~/pd-beaglebone_gpio && make"
