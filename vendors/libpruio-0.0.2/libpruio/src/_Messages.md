Messages  {#ChaMessages}
======
\tableofcontents

There are three instances for sharing messages

user  <-->  libpruio  <-->  PRU software

Communication between user and libpruio is necessary in case of
problems (errors). This gets done by passing human readable strings.
Informations from the PRU (ie. its current state) are decoded as a
binary number.


PRU States  {#SecPruState}
==========

The software on the PRU subsystem writes a code for its current state
to \ref PruIo::DRam[0]. The user can read this information and compare
it with the macros defined in file pruio.hp:

| Message            | Value      | Mode   | Meaning                     |
| -----------------: | :--------: | :----: | :-------------------------- |
| PRUIO_MSG_INIT_OK  | 4294967295 |  CTOR  | init successfully done      |
| PRUIO_MSG_EXIT_OK  | 4294967294 |  DTOR  | exit successfully done      |
| PRUIO_MSG_ADC_ERRR | 4294967293 | config | ADC device not ready        |
| PRUIO_MSG_IO_OK    | 4294967292 |   IO   | running in IO mode          |
| PRUIO_MSG_MM_WAIT  | 4294967291 |   MM   | waiting for mm_start call   |
| PRUIO_MSG_MM_TRG1  | 4294967290 |   MM   | waiting for trigger 1       |
| PRUIO_MSG_MM_TRG2  | 4294967289 |   MM   | waiting for trigger 2       |
| PRUIO_MSG_MM_TRG3  | 4294967288 |   MM   | waiting for trigger 3       |
| PRUIO_MSG_MM_TRG4  | 4294967287 |   MM   | waiting for trigger 4       |
| Fetching sample    | 0 to Samp  |   MM   | executing measurement       |

In MM mode the PRU software reports the currently used pointer to store
a sample. This is the offset in the \ref PruIo::ERam aray. Its maximum
value is \ref PruIo::Samples * \ref PruIo::ChAz `SHL 1` and the amount
of finished measurement in percent is \ref PruIo::DRam[0] / \ref
PruIo::Samples / \ref PruIo::ChAz `/ 2 * 100 %` .

When performing a pre-trigger, the value counts in the area of the
pre-trigger values (the ring buffer). It starts at zero and counts
upwards. When the upper border of the buffer is reached, it resets to
zero and counts upwards again, unless the trigger event happens. Then
it jumps to the real sample offset and counts in a continuous manner to
the end of the measurement.


Error Messages  {#SecErrors}
==============

All member functions of the PruIo class provide error messages in case
of a problem. Functions without return value (procedure type) return
the error message directly (or zero on success). For other functions
the error message can get accessed in the member variable \ref
PruIo::Errr. These are functions \ref PruIo::gpio_get(), \ref
PruIo::mm_trg_pin(), \ref PruIo::mm_trg_ain(), \ref PruIo::mm_trg_pre()
and the constructor. The function \ref PruIo::gpio_get_config() returns
either the error message or the configuration text.

Furthermore the member variable \ref PruIo::Errr allways contain the
error message (even when the function returns the error message
directly). Error messages are internal (hard-coded) strings and must
not be freed. libpruio does not reset the value, it gets holded until
the next error occurs. So its up to the user to reset the pointer to
zero when done with the message, to avoid unintended error positives
for old errors.

\note The destructor reports errors directly to the systems ERROUT pipe
     (since it can't use \ref PruIo::Errr member variable any more).

Here're all fuctions and their error messages, listed with the reason
for the problem and a hint how to solve it.


Constructor Errors  {#SubErrCtor}
------------------

\Item{unknown PRUSS - select 0 or 1} A wrong PRU number was passed ->
  select either 0 or 1 in the last parameter *Pru*.
\Item{failed opening uio5 interrupt} The interrupt to send messages from
  the PRU to the host couldn't get opened -> check the kernel driver
  and its configuration.
\Item{failed loading Pru_Init instructions} The driver couldn't load the
  instructions for the initialization to the PRU subsystem -> test
  function of prussdrv library.
\Item{failed executing Pru_Init instructions} Executing the
  initialization instructions failed -> check if other software uses
  this PRU.
\Item{failed starting ADC} The ADC device doesn't report a valid
  REVISION information -> ADC device may be broken.
\Item{out of memory} The driver couldn't allocate memory to store the
  original configuration of the divices -> make sure to have at least 1
  kByte of additional memory.


config Errors  {#SubErrConfig}
-------------

\Item{no step active} All step bits in the mask are zero -> set at least
  one step active, even if you don't need ADC values.
\Item{out of memory} The requested sample number needs more memory than
  available in the external memory block -> reduce parameter *Samp* or
  increase the size of the external memory. (See \ref ChaMemory for
  details).
\Item{sample rate too big} The ADC device needs more time to run through
  all active steps than available -> increase parameter *Tmr*.
\Item{failed loading parameters} The parameters for the driver couldn't
  get uploaded -> check libprussdrv functions.
\Item{failed loading Pru_Run instructions} The driver couldn't load the
  instructions to the PRU subsystem -> check libprussdrv functions.
\Item{failed executing Pru_Run instructions} The driver couldn't
  initialize the devices -> ADC device may be broken or other software
  uses the same PRU subsystem.


gpio_set Errors  {#SubErrSet}
---------------

\Item{unknown pin number} The ball index is too big -> pass a correct
  ball index in parameter *Ball*.
\Item{pin locked} New setting is forbidden since the ball is locked ->
  check ball number (or call this function with a proper setting for
  parameter *Lokk*).

gpio_get Error  {#SubErrGet}
--------------

\Item{unknown pin number} The ball index is too big -> pass a correct
  ball index in parameter *Ball*.


gpio_out Errors  {#SubErrOut}
---------------

\Item{unknown output pin number} The ball index is too big -> pass a
  correct ball index in parameter *Ball*.
\Item{input pin} You tried to set the state of an input CPU ball ->
  check ball number (or call function \ref PruIo::gpio_set() with
  proper setting for parameter *Modus* first).
\Item{output pin locked} Setting a new state is forbidden since the ball is
  locked -> check ball number (or call function \ref PruIo::gpio_set()
  with proper setting for parameter *Lokk* first).


gpio_get_config Error  {#SubErrGetConf}
---------------------

\Item{unknown pin number} The ball index is too big -> pass a correct
  ball index in parameter *Ball*.


adc_step Errors  {#SubErrStep}
---------------

\Item{step number too big} The step index is too big -> pass a correct
  step index in parameter *Stp* (0 = charge step, 1 to 16 = ADC steps,
  17 = idle step).
\Item{channel number too big} The channel index is too big -> pass a
  correct channel index in parameter *ChN* (0 = AIN0, 1 = AIN1, ..., 7
  = AIN7).


mm_trg_pin Errors  {#SubErrPin}
-----------------

\Item{unknown trigger pin number} The ball index is too big -> pass a
  correct ball index in parameter *Ball*.
\Item{pin must be in GPIO mode (mode 7)} The specified CPU ball is not
  in mode 7 (GPIO) -> check ball number (or call function \ref
  PruIo::gpio_set() with proper setting for parameter *Modus* first).
\Item{too much values to skip} The delay time is too big, this means too
  much samples to skip -> set parameter *Skip* with proper (lower)
  value (it's limited to the range of 0 to 1023). If you still need a
  longer waiting time, consider to increase the parameter *Tmr* for the
  next call to function \ref PruIo::config().


mm_trg_ain Errors  {#SubErrAin}
-----------------

\Item{invalid step number} The specified index for the trigger step is
  too big -> choose a step index in the range 1 to 16.
\Item{trigger step not configured} The specified trigger step
  is not configured -> either recreate the trigger specification or
  call function \ref PruIo::config() again and active the trigger step
  in parameter *Mask*.
\Item{too much values to skip} The delay time is too big, this means too
  much samples to skip -> set parameter *Skip* with proper (lower)
  value (it's limited to the range of 0 to 1023). If you still need a
  longer waiting time, consider to increase the parameter *Tmr* for the
  next call to function \ref PruIo::config().


mm_trg_pre Errors  {#SubErrPre}
-----------------

\Item{invalid step number} The specified index for the trigger step is
  too big -> choose a step index in the range 0 to 16.
\Item{trigger step not configured} The specified trigger step
  is not configured -> either recreate the trigger specification or
  call function \ref PruIo::config() again and active the trigger step
  in parameter *Mask*.
\Item{trigger step not activated} The trigger specification contains a
  trigger step that is not active in the \ref PruIo::StepMask -> either
  recreate the trigger specification or call function \ref
  PruIo::config() again and active the trigger step in parameter
  *Mask*.
\Item{too much pre-samples} There is not enough memory to sort the
  pre-trigger samples -> call function \ref PruIo::config() again and
  either reduce parameter *Samp* or choose less active steps in
  parameter *Mask*.
\Item{more pre-samples than samples} There are less samples than
  pre-trigger samples -> either reduce parameter *Samp* or call
  function \ref PruIo::config() again with increased parameter
  *Samp*.


mm_start Errors  {#SubErrStart}
--------------

\Item{Trg#: unknown trigger pin number} A digital trigger specifies a
  CPU ball number greater than the maximum -> check the trigger
  specification.
\Item{Trg#: trigger pin must be in mode 7 (GPIO)} A digital trigger
  specifies a CPU ball number that is not in GPIO mode -> check ball
  number, set CPU ball in mode 7.
\Item{Trg#: too much pre-trigger samples} There's not enough memory to
  sort the pre-trigger ring buffer -> call function \ref
  PruIo::config() again and reduce either parameter *Samp* or the
  number of active steps parameter *Mask*.
\Item{Trg#: pre-trigger step must be active} The pre-trigger specifies a
  step that isn't active in the \ref PruIo::StepMask -> either
  re-create the trigger specification or call function \ref
  PruIo::config() again with proper active steps parameter *Mask*


Destructor Errors  {#SubErrDtor}
-----------------

Destructor error messages cannot get passed in the \ref PruIo#Errr
variable (since this variable is invalid when the destructor returns).
These error messages get printed to the STDERR pipe directly.

\Item{failed loading Pru_Exit instructions} The driver couldn't load the
  exit instructions to the PRU subsystem -> test function of prussdrv
  library.
\Item{failed executing Pru_Exit instructions} Executing the
  exit instructions failed -> check if other software uses
  this PRU.
