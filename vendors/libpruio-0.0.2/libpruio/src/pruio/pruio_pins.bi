/'* \file pruio_pins.bi
\brief Pre-defined macros to handle the beagle bone header pins.

This file contains macros and arrays to easy handle the header pins and
pin groups of the beaglebone hardware. Instead of looking up the CPU
pin number in lists, you can use a macro named after the header and pin
number (ie pin 3 of header P8 is named P8_03).

Also included are pre-defined arrays for the pin groups of the
beaglebone black hardware. These contain all pins that belong to a
device like the EMMC2 or HDMI and can be used ie. to lock or unlock
these pins as one group.

'/

#define P8_03 6  ' emmc2
#define P8_04 7  ' emmc2
#define P8_05 2  ' emmc2
#define P8_06 3  ' emmc2
#define P8_07 36
#define P8_08 37
#define P8_09 39
#define P8_10 38
#define P8_11 13
#define P8_12 12
#define P8_13 9
#define P8_14 10
#define P8_15 15
#define P8_16 14
#define P8_17 11
#define P8_18 35
#define P8_19 8
#define P8_20 33 ' emmc2
#define P8_21 32 ' emmc2
#define P8_22 5  ' emmc2
#define P8_23 4  ' emmc2
#define P8_24 1  ' emmc2
#define P8_25 0  ' emmc2
#define P8_26 31
#define P8_27 56 ' hdmi
#define P8_28 58 ' hdmi
#define P8_29 57 ' hdmi
#define P8_30 59 ' hdmi
#define P8_31 54 ' hdmi
#define P8_32 55 ' hdmi
#define P8_33 53 ' hdmi
#define P8_34 51 ' hdmi
#define P8_35 52 ' hdmi
#define P8_36 50 ' hdmi
#define P8_37 48 ' hdmi
#define P8_38 49 ' hdmi
#define P8_39 46 ' hdmi
#define P8_40 47 ' hdmi
#define P8_41 44 ' hdmi
#define P8_42 45 ' hdmi
#define P8_43 42 ' hdmi
#define P8_44 43 ' hdmi
#define P8_45 40 ' hdmi
#define P8_46 41 ' hdmi

#define P9_11 28
#define P9_12 30
#define P9_13 29
#define P9_14 18
#define P9_15 16
#define P9_16 19
#define P9_17 87
#define P9_18 86
#define P9_19 95 ' i2c2
#define P9_20 94 ' i2c2
#define P9_21 85
#define P9_22 84
#define P9_23 17
#define P9_24 97
#define P9_25 107 ' mcasp0
#define P9_26 96
#define P9_27 105
#define P9_28 103 ' mcasp0
#define P9_29 101 ' mcasp0
#define P9_30 102
#define P9_31 100 ' mcasp0
#define P9_41 109
#define P9_42 89

'* CPU ball numbers for all pins on header P8
STATIC SHARED AS uint8 P8_Pins(...) = { _
  6  _
, 7  _
, 2  _
, 3  _
, 36 _
, 37 _
, 39 _
, 38 _
, 13 _
, 12 _
, 9  _
, 10 _
, 15 _
, 14 _
, 11 _
, 35 _
, 8  _
, 33 _
, 32 _
, 5  _
, 4  _
, 1  _
, 0  _
, 31 _
, 56 _
, 58 _
, 57 _
, 59 _
, 54 _
, 55 _
, 53 _
, 51 _
, 52 _
, 50 _
, 48 _
, 49 _
, 46 _
, 47 _
, 44 _
, 45 _
, 42 _
, 43 _
, 40 _
, 41 _
  }

'* CPU ball numbers for all digital pins on header P9
STATIC SHARED AS uint8 P9_Pins(...) = { _
  28  _
, 30  _
, 29  _
, 18  _
, 16  _
, 19  _
, 87  _
, 86  _
, 95  _
, 94  _
, 85  _
, 84  _
, 17  _
, 97  _
, 107 _
, 96  _
, 105 _
, 103 _
, 101 _
, 102 _
, 100 _
, 109 _
, 89  _
  }

'* CPU ball numbers for emmc2 pin group on header P8 (locked on BBB)
STATIC SHARED AS uint8 EMMC2_Pins(...) = { _
  6  _
, 7  _
, 2  _
, 3  _
, 33 _
, 32 _
, 5  _
, 4  _
, 1  _
, 0  _
  }

'* CPU ball numbers for hdmi pin group on header P8 (locked on BBB)
STATIC SHARED AS uint8 HDMI_Pins(...) = { _
  56 _
, 58 _
, 57 _
, 59 _
, 54 _
, 55 _
, 53 _
, 51 _
, 52 _
, 50 _
, 48 _
, 49 _
, 46 _
, 47 _
, 44 _
, 45 _
, 42 _
, 43 _
, 40 _
, 41 _
  }

'* CPU ball numbers for i2c1 pin group on header P9 (locked)
STATIC SHARED AS uint8 I2C1_Pins(...) = { _
  87 _
, 86 _
  }

'* CPU ball numbers for i2c2 pin group on header P9 (locked)
STATIC SHARED AS uint8 I2C2_Pins(...) = { _
  95 _
, 94 _
  }

'* CPU ball numbers for mcasp0 pin group on header P9 (locked)
STATIC SHARED AS uint8 MCASP0_Pins(...) = { _
  107 _
, 103 _
, 101 _
, 100 _
  }
