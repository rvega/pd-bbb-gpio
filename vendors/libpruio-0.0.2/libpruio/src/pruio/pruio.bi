/'* \file pruio.bi
\brief FreeBASIC header file for libpruio.

Header file for including libpruio to FreeBASIC programs. It contains
the declarations.

'/

#IFNDEF __PRUIO_COMPILING__
#INCLIB "pruio"
#ENDIF

'* tell pruss_intc_mapping.bi that we use ARM33xx
#DEFINE AM33XX

'* common macros, shared with PRU pasm compiler
#INCLUDE ONCE "pruio.hp"
'* the PRUSS driver library
#INCLUDE ONCE "BBB/prussdrv.bi"
'* PRUSS driver interrupt settings
#INCLUDE ONCE "BBB/pruss_intc_mapping.bi"

'* the channel for PRU messages (must match PRUIO_IRPT)
#DEFINE PRUIO_CHAN CHANNEL5
'* the mask to enable PRU interrupts (must match PRUIO_IRPT)
#DEFINE PRUIO_MASK PRU_EVTOUT5_HOSTEN_MASK
'* the event for PRU messages (mapping, must match PRUIO_IRPT)
#DEFINE PRUIO_EMAP PRU_EVTOUT5
'* the event for PRU messages (must match PRUIO_IRPT)
#DEFINE PRUIO_EVNT PRU_EVTOUT_5

'* the default setting for avaraging
#DEFINE PRUIO_DEF_AVRAGE 4
'* the default value for open delay in channel settings
#DEFINE PRUIO_DEF_ODELAY 183
'* the default value for sample delay in channel settings
#DEFINE PRUIO_DEF_SDELAY 0
'* the default PRU subsystem to use
#DEFINE PRUIO_DEF_PRUSS  1
'* the default number of samples to use (configures single mode)
#DEFINE PRUIO_DEF_SAMPLS 0
'* the default step mask (steps 1 to 8 for AIN0 to AIN7, no charge step)
#DEFINE PRUIO_DEF_STPMSK &b111111110
'* the default timer value (sampling rate)
#DEFINE PRUIO_DEF_TIMERV 0
'* the default bit mode (4 = 16 bit encoding)
#DEFINE PRUIO_DEF_LSLMOD 4
'* the default clock divisor (0 = full speed AFE = 2.4 MHz)
#DEFINE PRUIO_DEF_CLKDIV 0

'* convenience macro to configure an input pin without pullup or pulldown
#define PRUIO_IN    &b00101111
'* convenience macro to configure an low input pin (with pulldown resistor)
#define PRUIO_IN_0  &b00100111
'* convenience macro to configure an high input pin (with pullup resistor)
#define PRUIO_IN_1  &b00110111
'* convenience macro to configure an output pin initial low
#define PRUIO_OUT0  &b00001111
'* convenience macro to configure an output pin initial high
#define PRUIO_OUT1  &b10001111
'* convenience macro to re-configure a pin to its original (initial) state
#define PRUIO_PIN_RESET &b11111111

ENUM PRUIO_PIN_LOCKING
  PRUIO_UNLOCK_CURR '*< unlock a pin, don't change the configuration
  PRUIO_UNLOCK_ORIG '*< unlock a pin, change to original (initial) configuration
  PRUIO_UNLOCK_NEW  '*< unlock a pin, change to parameter configuration
  PRUIO_LOCK_CURR   '*< lock a pin, don't change the configuration
  PRUIO_LOCK_ORIG   '*< lock a pin, change to original (initial) configuration
  PRUIO_LOCK_NEW    '*< lock a pin, change to parameter configuration
  PRUIO_LOCK_CHECK  '*< don't change pin locking, skip operation if pin is locked
END ENUM

TYPE AS UINTEGER uint32 '*< 32 bit unsigned integer data type
TYPE AS USHORT uint16   '*< 16 bit unsigned integer data type
TYPE AS UBYTE uint8     '*< 8 bit unsigned integer data type
TYPE AS INTEGER int32   '*< 32 bit signed integer data type
TYPE AS SHORT int16     '*< 16 bit signed integer data type
TYPE AS BYTE int8       '*< 8 bit signed integer data type

'* user defined type for a step setting
TYPE AdcSteps
  AS uint32 _
    Confg _ '*< context for configuration register
  , Delay   '*< context for delay register
END TYPE

'* user defined type for a GPIO setting
TYPE GpioSet
  AS uint32 _
    Addr _ '*< base address of GPIO device
  , ClrM _ '*< mask to clear pins to low
  , SetM _ '*< mask to set pins to high
  , OutE _ '*< mask to enable pins for output
  , Stat _ '*< current state of pins (mixed)
  , StaO _ '*< current state of output pins
  , fe1  _ '*< future expansion
  , fe2
END TYPE

'* user defined type (class) for the driver structure
TYPE PruIo
'' don't change the order from here
  AS uint32 _
    Samples _  '*< number of samples
  , TimerVal _ '*< timer value in [ns]
  , StepMask   '*< mask to specify active channels
  AS uint16 _
    LslMode _  '*< bit shift modus (0 to 4)
  , ClockDiv   '*< divisor for ADC input clock (register 0x4C)

  AS uint32 _
    AdcReg24 = 0 _ '*< ADC register IRQ_STATUS_RAW
  , AdcReg28 = 0 _ '*< ADC register IRQ_STATUS
  , AdcReg2C = 0 _ '*< ADC register IRQENABLE_SET
  , AdcReg30 = 0 _ '*< ADC register IRQENABLE_CLR
  , AdcReg34 = 0 _ '*< ADC register IRQWAKEUP
  , AdcReg38 = 0 _ '*< ADC register DMAENABLE_SET
  , AdcReg3C = 0 _ '*< ADC register DMAENABLE_CLR
  , AdcReg40 = 0   '*< ADC register CRTL (bits 0, 1 and 2 gets set by driver)

  '* step configuration (charge step + 16 steps + idle step, by default steps 1 to 8 are used for AIN0 to AIN7)
  AS AdcSteps St_p(17)

  AS  uint32 PTR DRam   '*< pointer to access PRU DRam
'' don't change the order to here

  AS     ANY PTR ERam _    '*< pointer to read PRU external ram
               , BallOrg   '*< buffer pointer for original Ball configuration
  AS  uint32 PTR AdcOrg _  '*< buffer pointer for original ADC configuration (= 0 in case of ADC down at startup)
               , GpioOrg   '*< buffer pointer for original GPIO configuration
  AS  uint16 PTR Value     '*< pointer to read sampled ADC input data
  AS   uint8 PTR BallRef _ '*< pointer to ball reference (GPIO# for CPU pins or lock)
               , BallConf  '*< pointer to ball configuration (CPU pin muxing)
  AS ZSTRING PTR Errr = 0  '*< pointer for error messages
  AS uint32 _
    EOffs     _ '*< the offset of the external memory (PRUSS-DDR)
  , ESize     _ '*< the size of the external memory (PRUSS-DDR)
  , CSize     _ '*< the size of the original configuration block
  , PruNo     _ '*< the PRU number to use (defaults to 1)
  , PruEvtout _ '*< the interrupt channel to send commands to PRU
  , PruIRam   _ '*< the PRU instruction ram to load
  , PruDRam     '*< the PRU data ram
  AS int16 _
    ArmPruInt _ '*< the interrupt to send
  , ChAz        '*< number of active channels

  '* interrupt settings (we also set default interrupts, so that the other PRUSS can be used in parallel)
  AS tpruss_intc_initdata IntcInit = _
    TYPE<tpruss_intc_initdata>( _
      { PRU0_PRU1_INTERRUPT _
      , PRU1_PRU0_INTERRUPT _
      , PRU0_ARM_INTERRUPT _
      , PRU1_ARM_INTERRUPT _
      , ARM_PRU0_INTERRUPT _
      , ARM_PRU1_INTERRUPT _
      , PRUIO_IRPT _
      , CAST(BYTE, -1) }, _
      { TYPE<tsysevt_to_channel_map>(PRU0_PRU1_INTERRUPT, CHANNEL1) _
      , TYPE<tsysevt_to_channel_map>(PRU1_PRU0_INTERRUPT, CHANNEL0) _
      , TYPE<tsysevt_to_channel_map>(PRU0_ARM_INTERRUPT, CHANNEL2) _
      , TYPE<tsysevt_to_channel_map>(PRU1_ARM_INTERRUPT, CHANNEL3) _
      , TYPE<tsysevt_to_channel_map>(ARM_PRU0_INTERRUPT, CHANNEL0) _
      , TYPE<tsysevt_to_channel_map>(ARM_PRU1_INTERRUPT, CHANNEL1) _
      , TYPE<tsysevt_to_channel_map>(PRUIO_IRPT, PRUIO_CHAN) _
      , TYPE<tsysevt_to_channel_map>(-1, -1)}, _
      { TYPE<tchannel_to_host_map>(CHANNEL0, PRU0) _
      , TYPE<tchannel_to_host_map>(CHANNEL1, PRU1) _
      , TYPE<tchannel_to_host_map>(CHANNEL2, PRU_EVTOUT0) _
      , TYPE<tchannel_to_host_map>(CHANNEL3, PRU_EVTOUT1) _
      , TYPE<tchannel_to_host_map>(PRUIO_CHAN, PRUIO_EMAP) _
      , TYPE<tchannel_to_host_map>(-1, -1) }, _
      (PRU0_HOSTEN_MASK OR PRU1_HOSTEN_MASK OR _
       PRU_EVTOUT0_HOSTEN_MASK OR PRU_EVTOUT1_HOSTEN_MASK OR PRUIO_MASK) _
      )

  AS GpioSet PTR Gpio '*< pointer to GPIO structure (current values)
  '* initial GPIO definitions
  AS GpioSet GpioInit(PRUIO_GPIO_AZ) = { _
    TYPE<GpioSet>(&h44E07100uL, &h44E00408uL, 0, 0, 0, 0, 0, 0) _
  , TYPE<GpioSet>(&h4804C100uL, &h44E000ACuL, 0, 0, 0, 0, 0, 0) _
  , TYPE<GpioSet>(&h481AC100uL, &h44E000B0uL, 0, 0, 0, 0, 0, 0) _
  , TYPE<GpioSet>(&h481AE100uL, &h44E000B4uL, 0, 0, 0, 0, 0, 0) _
    }

  '* list of GPIO numbers, corresponding to ball index
  AS uint8 BallGpio(PRUIO_BALL_AZ) = { _
     32,  33,  34,  35,  36,   37,  38,  39,  22,  23 _
  ,  26,  27,  44,  45,  46,   47,  48,  49,  50,  51 _ ' 10
  ,  52,  53,  54,  55,  56,   57,  58,  59,  30,  31 _
  ,  60,  61,  62,  63,  64,   65,  66,  67,  68,  69 _ ' 30
  ,  70,  71,  72,  73,  74,   75,  76,  77,  78,  79 _
  ,  80,  81,   8,   9,  10,   11,  86,  87,  88,  89 _ ' 50
  ,  90,  91,  92,  93,  94,   95,  96,  97,  98,  99 _
  , 100,  16,  17,  21,  28,  105, 106,  82,  83,  84 _ ' 70
  ,  85,  29,   0,   1,   2,    3,   4,   5,   6,   7 _
  ,  40,  41,  42,  43,  12,   13,  14,  15, 101, 102 _ ' 90
  , 110, 111, 112, 113, 114,  115, 116, 117,  19,  20}

  DECLARE CONSTRUCTOR( _
    BYVAL AS uint8  = PRUIO_DEF_AVRAGE _
  , BYVAL AS uint32 = PRUIO_DEF_ODELAY _
  , BYVAL AS uint8  = PRUIO_DEF_SDELAY _
  , BYVAL AS uint8  = PRUIO_DEF_PRUSS)
  DECLARE DESTRUCTOR()
  DECLARE FUNCTION config CDECL( _
    BYVAL AS uint32 = PRUIO_DEF_SAMPLS _
  , BYVAL AS uint32 = PRUIO_DEF_STPMSK _
  , BYVAL AS uint32 = PRUIO_DEF_TIMERV _
  , BYVAL AS uint16 = PRUIO_DEF_LSLMOD _
  , BYVAL AS uint16 = PRUIO_DEF_CLKDIV) AS ZSTRING PTR
  DECLARE FUNCTION adc_step CDECL( _
    BYVAL AS uint8 _
  , BYVAL AS uint8 _
  , BYVAL AS uint8  = PRUIO_DEF_AVRAGE _
  , BYVAL AS uint8  = PRUIO_DEF_SDELAY _
  , BYVAL AS uint32 = PRUIO_DEF_ODELAY) AS ZSTRING PTR

  DECLARE FUNCTION gpio_get CDECL( _
    BYVAL AS uint8) AS uint32
  DECLARE FUNCTION gpio_set CDECL( _
    BYVAL AS uint8 _
  , BYVAL AS uint8 = PRUIO_IN_0 _
  , BYVAL AS uint8 = PRUIO_LOCK_CHECK) AS ZSTRING PTR
  DECLARE FUNCTION gpio_out CDECL( _
    BYVAL AS uint8 _
  , BYVAL AS uint8 = 0) AS ZSTRING PTR
  DECLARE FUNCTION gpio_get_config CDECL( _
    BYVAL AS uint8) AS ZSTRING PTR

  DECLARE FUNCTION mm_trg_pin CDECL( _
    BYVAL AS uint8 _
  , BYVAL AS uint8 = 0 _
  , BYVAL AS uint16 = 0) AS uint32
  DECLARE FUNCTION mm_trg_ain CDECL( _
    BYVAL AS uint8 _
  , BYVAL AS int32 _
  , BYVAL AS uint8 = 0 _
  , BYVAL AS uint16 = 0) AS uint32
  DECLARE FUNCTION mm_trg_pre CDECL( _
    BYVAL AS uint8 _
  , BYVAL AS int32 _
  , BYVAL AS uint16 = 0 _
  , BYVAL AS uint8 = 0) AS uint32
  DECLARE FUNCTION mm_start CDECL( _
    BYVAL AS uint32 = 0 _
  , BYVAL AS uint32 = 0 _
  , BYVAL AS uint32 = 0 _
  , BYVAL AS uint32 = 0) AS ZSTRING PTR
END TYPE

