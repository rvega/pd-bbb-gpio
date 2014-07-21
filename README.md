# Pd BeagleBone Black IO

This is a set of [PureData](http://puresata.info) externals (add-on objects) that allow for using the [BeagleBone Black's](http://beagleboard.org/black) analog and digital input and output pins. It is based on [libpruio](http://www.freebasic.net/forum/viewtopic.php?f=14&t=22501), which uses one of the [PRU]() units in the BeagleBone Black.

I have only tested this on a BeagleBone Black revision B, running Debian 7 and the 3.8.13-bone43 kernel. Also, I have only tested pins in header P9 of the BeagleBone.

## Usage

1. First, you need to configure the pins in the BBB as inputs or outputs and wether you want to use the internal pullup/pulldown resistors. This is done using a mechanism called device tree overlays. There are useful files for doing this in the device-tree-overlay directory. Refer to [this video]() for a nice explanation of how DTOs work.

2. Make sure the [bbb_input] and [bbb_output] externals are in PD's path and use them in your patches. Here are some screenshots with connection examples:

[!sddsds]()

## License

Copyright (C) 2014 Rafael Vega <rvega@elsoftwarehamuerto.org>

This program is free software: you can redistribute it and/or modify it 
under the terms of the GNU General Public License as published by the Free 
Software Foundation, either version 3 of the License, or (at your option) 
any later version.

This program is distributed in the hope that it will be useful, but WITHOUT 
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for 
more details.  

You should have received a copy of the GNU General Public License along 
with this program.  If not, see <http://www.gnu.org/licenses/>.
