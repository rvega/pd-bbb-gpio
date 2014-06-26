/'* \file pruio_c_wrapper.bi
\brief The main header code of the C wrapper for libpruio.

This is the header for the wrapper (used to auto-translate to file
pruio.h by fb-doc.

'/

#INCLUDE ONCE "../pruio/pruio.bas"

DECLARE FUNCTION pruio_new CDECL ALIAS "pruio_new"( _
    BYVAL  Av AS uint8 _
  , BYVAL OpD AS uint32 _
  , BYVAL SaD AS uint8 _
  , BYVAL Pru AS uint8) AS PruIo PTR
DECLARE SUB pruio_destroy CDECL ALIAS "pruio_destroy"(BYVAL Io AS PruIo PTR)
DECLARE FUNCTION pruio_config CDECL ALIAS "pruio_config"(BYVAL Io AS PruIo PTR, _
    BYVAL Samp AS uint32 _
  , BYVAL Mask AS uint32 _
  , BYVAL  Tmr AS uint32 _
  , BYVAL  Mds AS uint16 _
  , BYVAL ClDv AS uint16) AS ZSTRING PTR
DECLARE FUNCTION pruio_adc_step CDECL ALIAS "pruio_adc_step"(BYVAL Io AS PruIo PTR, _
    BYVAL Stp AS uint8 _
  , BYVAL ChN AS uint8 _
  , BYVAL  Av AS uint8 _
  , BYVAL SaD AS uint8 _
  , BYVAL OpD AS uint32) AS ZSTRING PTR
DECLARE FUNCTION pruio_gpio_get_config CDECL ALIAS "pruio_gpio_get_config"(BYVAL Io AS PruIo PTR, BYVAL Ball AS uint8) AS ZSTRING PTR
DECLARE FUNCTION pruio_gpio_set CDECL ALIAS "pruio_gpio_set"(BYVAL Io AS PruIo PTR, _
    BYVAL Ball AS uint8 _
  , BYVAL Modus AS uint8 _
  , BYVAL Lokk AS uint8) AS ZSTRING PTR
DECLARE FUNCTION pruio_gpio_get CDECL ALIAS "pruio_gpio_get"(BYVAL Io AS PruIo PTR, BYVAL Ball AS uint8) AS uint32
DECLARE FUNCTION pruio_gpio_out CDECL ALIAS "pruio_gpio_out"(BYVAL Io AS PruIo PTR, _
    BYVAL Ball AS uint8 _
  , BYVAL Modus AS uint8) AS ZSTRING PTR
DECLARE FUNCTION pruio_mm_trg_pin CDECL ALIAS "pruio_mm_trg_pin"(BYVAL Io AS PruIo PTR, _
    BYVAL Ball AS uint8 _
  , BYVAL GpioV AS uint8 _
  , BYVAL Skip AS uint16) AS uint32
DECLARE FUNCTION pruio_mm_trg_ain CDECL ALIAS "pruio_mm_trg_ain"(BYVAL Io AS PruIo PTR, _
    BYVAL Stp AS uint8 _
  , BYVAL AdcV AS int32 _
  , BYVAL Rela AS uint8 _
  , BYVAL Skip AS uint16) AS uint32
DECLARE FUNCTION pruio_mm_trg_pre CDECL ALIAS "pruio_mm_trg_pre"(BYVAL Io AS PruIo PTR, _
    BYVAL Stp AS uint8 _
  , BYVAL AdcV AS int32 _
  , BYVAL Samp AS uint16 _
  , BYVAL Rela AS uint8) AS uint32
DECLARE FUNCTION pruio_mm_start CDECL ALIAS "pruio_mm_start"(BYVAL Io AS PruIo PTR, _
    BYVAL Trg1 AS uint32 _
  , BYVAL Trg2 AS uint32 _
  , BYVAL Trg3 AS uint32 _
  , BYVAL Trg4 AS uint32) AS ZSTRING PTR
