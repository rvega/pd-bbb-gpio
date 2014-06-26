echo PRUSSDRV > /sys/devices/bone_capemgr.9/slots
chown root:pruio /dev/uio5
chmod g+rw /dev/uio5
ls -l /dev/uio*
