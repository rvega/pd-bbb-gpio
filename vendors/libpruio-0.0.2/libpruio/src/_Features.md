Features  {#ChaFeatures}
========
\tableofcontents

libpruio features in short

- wakeup devices (GPIO and ADC)
- read original devices configuration (if any)
- customize GPIO configuration
- customizing from user-point-of-view (header pins instead of CPU ball numbers)
- create a text description for a GPIO configuration
- lock or unlock GPIOs
- customize ADC configuration and channel settings
- run in IO mode (IO) or measurement mode (MM)
- get GPIO input state (IO)
- set GPIO output state (IO)
- fetch ADC samples continuously (IO)
- fetch a given number of samples for a given set of channels (MM)
- start measurement by one or up to four trigger events (MM)
- absolute or delta triggers (MM)
- post-triggers start sampling after a certain time (MM)
- pre-trigger starts sampling before the trigger event happened (MM)
- transform ADC samples to 13, 14, 15 or 16 bit values
- restore previous settings when done (if any)
- run either on PRU-0 or PRU-1 (default)

Functional Description  {#SecFunction}
======================

This driver uses a PRU subsystem to operate the ARM devives Control
Module, GPIO[0-3] and TSC_ADC_SS. The software can either run on PRU-0
or on PRU-1 (the later is the default) and is highly configurable.

To run this library the PRU subsystems must be enabled and read / write
privilegues are necessary to the PRU system interrupt `/dev/uio5`,
see \ref ChaPreparation for details.

Operation gets done in three steps

-# wake up and prepare ADC and GPIO devices, fetch original configuration
-# configure devices
  - customize GPIO settings (optional)
  - customize ADC channel settings (or use defaults)
  - upload settings to PRU and start (in IO mode) or wait for start command (in MM mode)
  - start measurement (MM)
-# when done, restore original configuration (if any) and destroy driver UDT

After configuration the driver software runs on the PRU subsystem in an
endless loop. Interrupt this loop by either uploading a new
configuration or destroying the driver structure.

The driver either runs in input / output mode (IO) or measurement mode
(MM). In IO mode the software on the host (ARM) controls the data flow
and the driver continuously transfers values to and from the devices.
In MM mode the software on the host starts the execution and then waits
until the driver software on the PRU finished the specified
measurement.

All parameters for the ADC device are stored local in the PruIo
structure and get uploaded by a call the function \ref PruIo::config().
GPIO settings can get changed at runtime (in IO mode).


Constructor  {#SubConstructor}
-----------

The constructor \ref PruIo::PruIo() creates a new driver structure and
prepares the devices. It wakes up the GPIO and ADC devices (if powered
off) or reads the original configuration (if already running).

The digital input lines (GPIO) are used unchanged. All lines connected
to one of the Beaglebone headers P8 or P9 get checked. Each connector
(pin) that is configured in mode 7 (GPIO) gets unlocked. Pins in other
modes and pins not connected to a header get locked.

A set of ADC step configurations get created with default values. Step
1 to 8 are set to sample inputs AIN0 to AIN7 with an avaraging of 4
samples and an open delay of 200 cycles, resulting in a sampling rate
of 10 kilo samples per second. Pass parameters to customize avaranging,
open delay and sample delay for the steps in the default configuration.

Later, these default settings can get extended by additional steps or
the default steps can get overriden by customized parameters.

\note Never create more than one instance of the PruIo at a time. They
      may interfere on memory or interrupt settings. Destroy the first
      instance before creating a new one.


GPIO Pin Configuration  {#SubCustomizePin}
----------------------

The function \ref PruIo::gpio_set() is used to customize the
configuration of CPU connectors (balls). The Control Module in the ARM
processor is used to connect a CPU ball to an internal CPU device. To
use a ball as GPIO, it must be set in mode 7. In this mode it can
either be an input or an output. Input balls can optionally get
connected to a pullup or pulldown resistor. Output balls get set to an
initial high or low state (and have no resistor connected by default).

The libpruio user need not care about CPU balls. The extension
pruio_pins.bi contains macros to perform configurations from the user
point of view. These macros hide the CPU ball number behind an easy to
understand name in case of all balls connected to a Beaglebone header
(P8 or P9). In contrast to the CPU balls these connectors are called
pin in this document. Ie. use 'P8_07' to refer to the CPU ball
connected to pin 7 on header P8. The file pruio_pins.bi also contains
arrays to easy address groups of pins.

libpruio contains a locking mechanism to protect unintentional pin
changes. All balls are locked by default, except the pins (balls
connected to a Beaglebone header P8 or P9) that are configured in mode
7 at startup (these get unlocked by the constructor). The user is free
to customize the locking by calls to function \ref PruIo::gpio_set().


GPIO Pin Description  {#SubDescripbePin}
--------------------

The function \ref PruIo::gpio_get_config() creates a human readable
desription of a current CPU ball setting. Detailed information are
generated for balls in mode 7 (GPIO). Otherwise only the mode number
gets shown.

This function can be used on all CPU balls. Pins on the headers are
named after their position (ie. like "H8_46") and internaly connected
CPU balls are named by their Control Module reference number (ie.
"b097").


ADC Step Configuration  {#SubCustomizeStep}
----------------------

The function \ref PruIo::adc_step() is used to customize the
configuration for a single channel. Changes get stored in to the local
settings in the driver structure and take into acount after uploading
the driver configuration by the next call to function \ref
PruIo::config().


ADC Settings  {#SubCustomizeAdc}
------------

Furthermore (for advanced users) some registers of the ADC device can
get influenced by changing the member variables \ref PruIo::AdcReg24 to
\ref PruIo::AdcReg40 (ie. IRQ and DMA settings). These get uploaded to
the ADC device by each call to function \ref PruIo::config().


Config  {#SubConfig}
------

The function \ref PruIo::config() uploads the local driver
configuration (from the host = ARM) and the instructions to the PRU
device. And it starts executing the program, which configures the
devices Arm Control Module, GPIOs and ADC.

Depending on the requirend number of samples it either immediately
starts in IO mode or waits for a call to \ref PruIo::mm_start() in MM
mode.


Digital IO  {#SubDIO}
----------

Digital input and output is available in IO mode. Set the state of an
output pin by a call to function \ref PruIo::gpio_out() or get the
state of an input or output pin by a call to function \ref
PruIo::gpio_get(). You can get the state of all pins, but setting
the state is only allowed for unlocked pins in output mode. Use
function \ref PruIo::gpio_set() to change pin mode and locking.

\note Digital IO is only available in IO mode. It doesn't work in MM mode.


Analog Input  {#SubAI}
------------

Analog input is available in IO mode and in MM mode. In MM mode the
driver fetches a pre-defined set of samples in real time (and does
nothing else). In IO mode the driver updates the ADC samples
continuously and the software on the host (ARM) controls when to fetch
a value. Switch between both modes by setting the parameter Samp in a
call to function \ref PruIo::config().

Refer to the samples of the ADC device by the member array \ref
PruIo::Value. Its context depends on the execution mode. In IO mode the
array contains one value for each step. Non-active steps are set to 0
(= zero). Active steps contain the last sampled value. In MM mode the
array contains only valid samples (all zero values of non-active steps
get skipped).

The sampled values can get scaled in 12 to 16 bit resolution (ie. to
directly compare the values with results from a 16 bit audio device).
See parameter Mds for function \ref PruIo::config() for details.

In IO mode the sampling rate depends on the configuration of the ADC
device and the steps. The parameter ClkDiv and the avaraging, the open
and the sample delay values specify the time the ADC device needs to
execute a run through all active steps. When such a run is finished the
driver starts the ADC device again. (The timing of the re-start may
vary a few micro seconds.)

In MM mode the sampling rate gets defined by the parameter Tmr in the
call to function \ref PruIo::config(). In this mode the driver uses an
internal CPU timer to garanty maximum timing precision.


Start (MM)  {#SubStart}
----------

The function \ref PruIo::mm_start() is used to start a measurement in
measurement mode (MM). By default (no parameters) the measurement
starts immediately. Otherwise the measurement starts after all
specified trigger events happend. Up to four trigger events can get
specified by parameters. In case of more than one trigger event, the
first trigger starts the second, the second starts the third and so on.
Measurement doesn't start before all trigger events happened in the
given order.

Trigger events can either be specified as an event on a digital or
analog line. In case of a digital event the trigger waits until the
specified input or output GPIO gets in the given state. In case of an
analog trigger a specified ADC step gets executed and the resulting
sample gets compared with the trigger setting. Delay times can be added
after, but for an analog trigger also before the trigger event happens
(see below).

This function is designed for synchronuous calls. It waits until all
trigger events occured and the measurement is finished. Enclose it in a
thread when you need asynchronous execution. But never execute more
than one call at a time. When running in a thread the current state can
get checked in the member variable \ref PruIo::DRam[0]. See \ref
ChaMessages for details.


Digital Trigger (MM)  {#SubTrigPin}
--------------------

An digital trigger is used to start a measurement in MM. It compares
the state of the given CPU ball against the specified trigger value.
Input or output balls can be used as trigger.

Use function \ref PruIo::mm_trg_pin() to create a digital trigger
specification and pass it in the call to function \ref
PruIo::mm_start().

During the waiting phase only the GPIO state gets checked and the ADC
device is in idle mode. After the trigger event happened, the ADC gets
started, all configured steps get active and sampling rate slows down
to the specified value.

A delay time can get added after the trigger event and before the
measurement (or the next trigger) starts.


Analog Trigger (MM)  {#SubTrigAin}
-------------------

An analog trigger is used to start a measurement in MM. It compares the
current sample of the given ADC step against the specified trigger
value. The trigger event happens if the current sample is either
greater or less than the specified trigger value. The trigger value can
either be an absolute value or it can get specified as relative change.

Use function \ref PruIo::mm_trg_ain() to create an analog trigger
specification and pass it in the call to function \ref
PruIo::mm_start().

During the waiting phase only the trigger step is active and the ADC
device runs at maximum sampling rate with the previously configured ADC
settings (all other steps are disabled). After the trigger event
happened, all configured steps get active and sampling rate slows
down to the specified value.

A delay time can get added after the trigger event and before the
measurement (or the next trigger) starts.


Pre-Trigger (MM)  {#SubTrigPre}
----------------

An pre-trigger is used to start a measurement in MM. In contrast to the
previous triggers a pre-trigger starts measurement before the trigger
event happens. This means the measurement gets started immediately,
doing all active steps. The samples get stored in a ring buffer,
overriding old values when the buffer is full. When the trigger event
happens, measurement continues but the samples get stored in the normal
buffer (outside the ring buffer). After the measurement the samples in
the ring buffer get sorted in the right order.

Currently a pre-trigger only can use an analog input line (but no
digital). It's possible to either trigger on one or all active analog
steps.

Use function \ref PruIo::mm_trg_pre() to create a specification for a
pre-trigger and pass it in the call to function \ref PruIo::mm_start().
A pre-trigger is allways the last trigger specification (further specs
get ignored).


Destructor  {#SubDestructor}
----------

The destructor resets the devices Control Module, GPIOs and ADC to the
original state. It powers off the devices or restores the original
configurations (if they were running on start-up). Then it frees the
memory used by the driver structure.

It's possible to override the original configurations (only useful for
advanced users and undocumented, check source code and \ArmRef{9, 12
and 25} for details).


PRU subsystem  {#SubPru01}
-------------

The driver is designed to run either on PRU-0 or PRU-1 subsystem, so
you can use the other PRU system for additional purposes. By default it
runs on PRU-1 (see \ref PruIo::PruIo to customize) and uses its DRam
memory area. In case of a pre-trigger (in MM mode) the DRam from the
other PRU may be used to sort the samples, see \ref ChaMemory for
details.
