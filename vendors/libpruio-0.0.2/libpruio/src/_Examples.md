Examples  {#ChaExamples}
========
\tableofcontents

This page contains some example code. A very simple example is shown as
source code here. The other examples are described in text form. Find
the corresponding source code and pre-compiled binaries in the folder
*examples*.

\note Make sure you followed the installation instructions in \ref
      SubPreSystem before you execute a sample program.

Feel free to send your testing code (max. 200 LOC) to the author for
extending this section:

\Email


Console examples  {#SecExaConsole}
================

The following examples are designed to run in text mode at the console.


1.bas  {#SecExaSimple}
-----

This example operates the driver in IO mode. Default settings are used
to read the analog input lines AIN 0 to 7 and output 13 lines of sampled
data at the console. It's designed as a minimal example to show the
basic code.

The output of the program looks like (FreeBASIC version)

~~~{.txt}
 D530 E0C0 DE20 CEE0 0080 0780 1850 EE20
 E990 E150 DD80 D010 0000 07A0 1770 EE00
 E980 E230 DE70 CEE0 0070 07B0 17A0 EE30
 E9C0 E110 DD50 CF00 0090 08C0 18D0 EE40
 E8D0 E0B0 DD10 CE60 0010 0880 1800 EE40
 E9B0 E210 DDC0 CEC0 0090 0790 1850 EE00
 E970 E220 DE40 D020 00D0 0840 17D0 EE70
 E9D0 E1C0 DD90 CE90 00B0 06F0 1830 EE70
 E920 E120 DC90 CD80 0040 0750 1850 EDF0
 E8E0 E0D0 DD60 CEC0 00B0 0810 1780 EEB0
 E8D0 E130 DD00 CE90 0000 0730 17D0 EE70
 EA20 E210 DDD0 CED0 00E0 0820 1850 EEA0
 E960 E0D0 DDE0 CF10 0010 0740 17B0 EE40
~~~

First the source code of the FreeBASIC version (unfortunately with
incorrect syntax highlighting - this Doxygen version cannot switch off
the highlighting):

~~~{.bas}
#INCLUDE ONCE "../pruio/pruio.bi" '*  include header
VAR io = NEW PruIo()              '*< create new driver UDT
io->config()                      '   upload (default) settings, start IO mode

''     now current ADC samples are available for AIN0 to AIN7 in array Value[]

FOR n AS INTEGER = 1 TO 13 ''                                 print some lines
  FOR i AS INTEGER = 1 TO 8 ''                                       all steps
    PRINT " " & HEX(io->Value[i], 4); ''     output one channel as hexadecimal
  NEXT
  PRINT ''                                                           next line
NEXT

'' we're done

DELETE io                         '   destroy driver UDT
~~~

And here's a similar version in C syntax:

\dontinclude examples/1.c
\skipline #include
\until } // end of main

\note C syntax doesn't support default parameters. You've to pass all
      parameters when using a C compiler.


analyse.bas  {#SubExaAnalyse}
-----------

This example shows how to get information about the original devices
configurations. It creates a new PruIo instance and analyses the
original (initial) configuration of the devices GPIOs, Control Module
and ADC. It's designed to run in console mode and stops after printing
out a listing like

~~~{.txt}
GPIO0 was on
    OE: 11111111111111111111111111111111
  INT0: 00000000000000000000000000000000
  INT1: 00000000000000000000000000000000
GPIO1 was on
    OE: 11110110000011111111111111111111
  ...
Unlocked Pins:
  P8_19, GPIO 0/22: input, pulldown
  ...
Locked header Pins:
  P8_03, mode 1 (locked)
  ...
ADC was off
      REVISION: 47300001
  wakeup-count: 00000002
~~~

A similar version in C syntax is included named analyse.c.


io_input.bas  {#SubExaIoInp}
------------

This example shows how to get input from digital and analog devices. It
creates a new PruIo instance and prints out the state of all the
digital and analog lines. It's designed to run in console mode and
creates continuous output like

~~~{.txt}
   .   |   .   |   .   |   .   |
00000000000000000000000000000000
00001000101000000000000000000000
00000000000000000000000000100100
00000000000000000000000000000000
EF10 E850 E660 D8C0  2C60 2C00 3710 EE80
~~~

The first line is a scale to support identifying the bit positions. The
next four lines show the state of the GPIOs 0 to 3. The last line is
the sampled ADC data form AIN 0 to 7 as hexadecimal values in 16 bit
format.

You can watch the heartbeat (user LED 0) in the third line (GPIO-1, bit
21). The last analog value (AIN7) is the measured voltage on the board
(it should be the half of 3.3 V: &hEE80 * 1.8 V / (4095 SHL 4) = 1.677
V).

To quit the program press any key.

A version in C syntax is included named io_inout.c. This version prints
out all values in one line and uses octal numbers for the GPIO state,
instead of binary numbers.


sos.bas  {#SubExaSos}
-------

This example shows how to unlock and control an internal CPU ball. It
creates a new PruIo instance and unlocks the User3 LED ball as output.
Then it continuously blinks this LED in SOS code (short, short, short -
long, long, long - short, short, short). The output looks like:

~~~{.txt}
watch SOS code on user LED 3 (near ethernet connector)

execute this command to get rid of mmc1 triggers
  sudo su && echo none > /sys/class/leds/beaglebone:green:usr3/trigger && exit

press any key to quit
~~~

The blinking code may get disturbed by the system (kernel), which is
also blinking the LED on mmc1 interrupts. Execute the mentioned command
to get rid of this interferences. (Replace 'none' by 'mmc1' to restore
the original configuration.)

To quit the program press any key.

A similar version in C syntax is included named sos.c.


button.bas  {#SubExaButton}
-----------

This example shows how to use a header pin as input. It creates a new
PruIo instance and sets pin 7 on header P8 in input mode with pullup
restistor, so that the GPIO state is high (= 1) when unconnected. The
program outputs a single line containing the GPIO state, updated
continously until any keypress.

When the pin gets grounded, the state changes to low (= 0). This can be
done by connecting a cable between P8_07 (GPIO input) and P8_01 (GND).
Or you connect a button to these pins an see the state changing to zero
when pressing the button. Instead, you also can connect a photoelectric
sensor (ie. the detector part of a forked light barrier: + on P8_07, -
on P8_01, and supply the emitter part by an appropriate voltage /
current).

~~~{.txt}
1
~~~

A similar version in C syntax is included named button.c.


stepper.bas  {#SubExaStepper}
-----------

This example shows how to use header pins as output. It creates a new
PruIo instance and sets four header pins in output mode to control a
stepper motor. Connect a common GRND and the inputs of the stepper
driver board to pins H8_08, H8_10, H8_12 and H8_14. Ie. use a x113647
driver board and a 28BYJ-48 stepper motor. (Note: the header pin output
is 3.3 V by a maximum current of 5 mA). This program is designed to
run in console mode and prints out user information like

~~~{.txt}
Controls: (other keys quit, 1 and 3 only when Direction = 0)
                       8 = faster
  4 = rotate CW        5 = stop, hold position   6 = rotate CCW
  1 = single step CW   2 = slower                3 = single step CCW
  0 = stop, power off

Direction     Speed
 0             2
~~~

The user can control speed and direction of the motor by pressing the
listed keys. Ie. press

- key 1 to move a single step,
- then key 4 to start continuous rotation,
- then key 8 to speed up rotation or
- key 2 to slow down,

and so on. Any other (not listed) keystroke quits the program.

A similar version in C syntax is included named stepper.c.


Grafic examples  {#SecExaGrafic}
===============

The following examples are designed to run in grafic mode. They open a
grafic window. You need a display connected to the Beaglebone (ie. a
HDMI monitor). Sorry, no C versions (due to long and complex code for
grafics).


oszi.bas  {#SubExaOszi}
--------

This example shows how to receive fast ADC input in IO mode. It opens a
grafic window and creates a new PruIo instance for drawing continuously
the sampled analog data from all channels (AIN0 to AIN7) as line grafic
with colored lines. By default it creates a full screen window without
a frame. You can customize the window by setting the size as command
line option (ie like `./oszi 640x400` for width = 640 and hight = 400).

The grafic is scaled 0 V at the bottom and 1.8 V at the top. You can
toggle the channels on or off by pressing keys 0 to 7 (0 = AIN0, ... 7
= AIN7), but you cannot de-activate the last channel (at least one
channel stays active). Key '+' restores the default setting (all
channels active). Any other key quits the program.

The less channels are activated, the faster the ADC device samples the
data. Ie. check it by connecting a constant frequency sine wave (0 to
maximal 1.8 V) to a channel and switch off the others one by one.


triggers.bas  {#SubExaTriggers}
------------

This example shows how to use triggers to start a measurement in MM
mode and how to customize an ADC step (for the analog trigger 2). It
opens a grafic window and creates a new PruIo instance for MM. By
default it creates a full screen window without a frame. You can
customize the window by setting the size as command line option (ie
like `./triggers 640x400` for width = 640 and hight = 400).

The grafic is scaled 0 V at the bottom and 1.8 V at the top. The
sampling rate is 1 kHz. You can start a measurement of two channels
(AIN4 and AIN7) by a trigger. Choose one of the trigger types form the
menu

~~~{.txt}
Choose trigger type
  0 = no trigger (start immediately)
  1 = GPIO trigger (pin P8_07)
  2 = analog trigger (AIN4 > 0.9 V)
  3 = analog pre-trigger (any AIN < 0.9 V)
~~~

Further keystrokes (other than 0 to 3) quit the program.

After choosing a trigger type (1 to 3), the program waits for the
trigger event. So make sure to prepare a cable to connect header pins
before testing.

Here's an instruction how you can test the program. First, execute the
binary with a customized window size by

~~~{.txt}
./triggers 640x400
~~~

and you'll see the above mentioned menu in an empty grafic window. The
next steps depend on the trigger to test:

<b>0 = no trigger (start immediately)</b>
-# Press key 0. After a short while (less than 1 second) a red and a
  white line show up in the window. White = AIN4 (open connector) shows
  any signal and red = AIN7 (board voltage = 1.65 V) is always at the
  top of the window. The menu showns up again for the next test.

<b>1 = GPIO trigger (pin P8_07)</b>
-# Press key 1 to start the trigger. You'll see a new message `waiting
  for GPIO trigger (pin P8_07 low) ...`. Nothing else happens.
-# Use a cable to connect P8_01 (GRND) and P8_07 (trigger pin). After a
  short while (less than 1 second) a red and a white line show up in
  the window. White = AIN4 (open connector) shows any signal and red =
  AIN7 (board voltage = 1.65 V) is always at the top of the window. The
  menu showns up again for the next test.

<b>2 = analog trigger (AIN4 > 0.9 V)</b>
-# Connect a cable between P9_34 (AGND) and P9_33 (AIN4).
-# Press key 2 to start the trigger. You'll see a new message `waiting
  for analog trigger (AIN4 > 0.9 V) ...`. Nothing else happens.
-# Release the cable. The channel AIN7 will pull up the open trigger
  channel AIN4 to a voltage above the trigger voltage. (If this doesn't
  happen, connect the cable between P9_32 (VADC) and P9_33 (AIN4).)
  After a short while (less than 1 second) a red and a white line show
  up in the the window. White = AIN4 (open connector) starts on the
  left side at the middle of the window hight (the trigger event) and
  shows any signal. Red = AIN7 (board voltage = 1.65 V) is always at
  the top of the window. The menu showns up again for the next test.

<b>3 = analog pre-trigger (any AIN < 0.9 V)</b>
-# Connect a cable between P9_32 (VADC) and P9_33 (AIN4).
-# Press key 3 to start the trigger. You'll see a new message `waiting
  for analog pre-trigger (any AIN < 0.9 V) ...`. Nothing else happens.
-# Release the cable. The open trigger channel AIN4 starts to swing
  below the trigger voltage. (If this doesn't happen, connect the cable
  between P9_34 (AGND) and P9_33 (AIN4).) After a short while (less
  than 1 second) a red and a white line show up in the the window.
  White = AIN4 (open connector or AGND) goes across the middle of the
  window (the trigger event) and shows any signal in the upper left
  (pre-trigger samples) and some parts of the curve in the lower right
  (regular samples after trigger event). Red = AIN7 (board voltage =
  1.65 V) is always at the top of the window. The menu showns up again
  for the next test.
