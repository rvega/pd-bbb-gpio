/'* \file pruio_c_wrapper.bas
\brief The main source code of the C wrapper for libpruio.

This file provides the \ref PruIo class member functions in a C
compatible syntax to use libpruio in polyglot applications or to create
language bindings for non-C languages.

Licence: LGPLv2 (http://www.gnu.org/licenses/lgpl-2.0.html)

Copyright 2014 by Thomas{ dOt ]Freiherr[ At ]gmx[ DoT }net


compile by (static and dynamic library)

./build

'/


#DEFINE __PRUIO_COMPILING__

'* Driver file.
#INCLUDE ONCE "../pruio/pruio.bas"
'* Header file.
#INCLUDE ONCE "pruio_c_wrapper.bi"


FUNCTION pruio_new CDECL( _
    BYVAL  Av AS uint8 _
  , BYVAL OpD AS uint32 _
  , BYVAL SaD AS uint8 _
  , BYVAL Pru AS uint8) AS PruIo PTR EXPORT

  RETURN NEW PruIo(Av, OpD, SaD, Pru)
END FUNCTION


/'* \brief C wrapper to destroy a \ref PruIo instance.
\param Io The pointer of the instance.

This function wraps the destructor, check \ref PruIo::~PruIo() for
details.

'/
SUB pruio_destroy CDECL(BYVAL Io AS PruIo PTR) EXPORT
  IF Io THEN DELETE Io : Io = 0
END SUB


FUNCTION pruio_config CDECL(BYVAL Io AS PruIo PTR, _
    BYVAL Samp AS uint32 _
  , BYVAL Mask AS uint32 _
  , BYVAL  Tmr AS uint32 _
  , BYVAL  Mds AS uint16 _
  , BYVAL ClDv AS uint16) AS ZSTRING PTR EXPORT

  RETURN Io->config(Samp, Mask, Tmr, Mds, ClDv)
END FUNCTION


FUNCTION pruio_adc_step CDECL(BYVAL Io AS PruIo PTR, _
    BYVAL Stp AS uint8 _
  , BYVAL ChN AS uint8 _
  , BYVAL  Av AS uint8 _
  , BYVAL SaD AS uint8 _
  , BYVAL OpD AS uint32) AS ZSTRING PTR EXPORT

  RETURN Io->adc_step(Stp, ChN, Av, SaD, OpD)
END FUNCTION


FUNCTION pruio_gpio_get_config CDECL(BYVAL Io AS PruIo PTR, BYVAL Ball AS uint8) AS ZSTRING PTR EXPORT

  RETURN Io->gpio_get_config(Ball)
END FUNCTION


FUNCTION pruio_gpio_set CDECL(BYVAL Io AS PruIo PTR, _
    BYVAL Ball AS uint8 _
  , BYVAL Modus AS uint8 _
  , BYVAL Lokk AS uint8) AS ZSTRING PTR EXPORT

  RETURN Io->gpio_set(Ball, Modus, Lokk)
END FUNCTION


FUNCTION pruio_gpio_get CDECL(BYVAL Io AS PruIo PTR, BYVAL Ball AS uint8) AS uint32 EXPORT
  RETURN Io->gpio_get(Ball)
END FUNCTION


FUNCTION pruio_gpio_out CDECL(BYVAL Io AS PruIo PTR, _
    BYVAL Ball AS uint8 _
  , BYVAL Modus AS uint8) AS ZSTRING PTR EXPORT

  RETURN Io->gpio_out(Ball, Modus)
END FUNCTION


FUNCTION pruio_mm_trg_pin CDECL(BYVAL Io AS PruIo PTR, _
    BYVAL Ball AS uint8 _
  , BYVAL GpioV AS uint8 _
  , BYVAL Skip AS uint16) AS uint32 EXPORT

  RETURN Io->mm_trg_pin(Ball, GpioV, Skip)
END FUNCTION


FUNCTION pruio_mm_trg_ain CDECL(BYVAL Io AS PruIo PTR, _
    BYVAL Stp AS uint8 _
  , BYVAL AdcV AS int32 _
  , BYVAL Rela AS uint8 _
  , BYVAL Skip AS uint16) AS uint32 EXPORT

  RETURN Io->mm_trg_ain(Stp, AdcV, Rela, Skip)
END FUNCTION


FUNCTION pruio_mm_trg_pre CDECL(BYVAL Io AS PruIo PTR, _
    BYVAL Stp AS uint8 _
  , BYVAL AdcV AS int32 _
  , BYVAL Samp AS uint16 _
  , BYVAL Rela AS uint8) AS uint32 EXPORT

  RETURN Io->mm_trg_pre(Stp, AdcV, Samp, Rela)
END FUNCTION


FUNCTION pruio_mm_start CDECL(BYVAL Io AS PruIo PTR, _
    BYVAL Trg1 AS uint32 _
  , BYVAL Trg2 AS uint32 _
  , BYVAL Trg3 AS uint32 _
  , BYVAL Trg4 AS uint32) AS ZSTRING PTR EXPORT

  RETURN Io->mm_start(Trg1, Trg2, Trg3, Trg4)
END FUNCTION
