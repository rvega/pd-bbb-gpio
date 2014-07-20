PD-BBB-IO-00A0.dtbo: build

build: PD-BBB-IO.dts
	dtc -O dtb -o PD-BBB-IO-00A0.dtbo -b 0 -@ PD-BBB-IO.dts 

.PHONY: clean
clean:
	rm PD-BBB-IO-00A0.dtbo

.PHONY: install
install: PD-BBB-IO-00A0.dtbo
	cp PD-BBB-IO-00A0.dtbo /lib/firmware

.PHONY: uninstall
uninstall: 
	rm /lib/firmware/PD-BBB-IO-00A0.dtbo

.PHONY: load
load:
	echo PD-BBB-IO > /sys/devices/bone_capemgr.9/slots

.PHONY: unload
unload:
	echo -`cat /sys/devices/bone_capemgr.9/slots | grep PD-BBB-IO | sed 's/:.*//' | sed 's/ //'` > /sys/devices/bone_capemgr.9/slots
