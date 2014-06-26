Memory Organisation  {#ChaMemory}
===================

libpruio uses memory to exchange data between the host (ARM) and PRU
subsystem. Parameters need to be passed to the PRU subsystem, data get
exchanged in both directions. The kernel driver allocates memory areas
for that purpose. libpruio uses

- the PRU specific DRam in IO mode and
- both DRam areas and the external memory in MM mode.

In IO mode the driver uses DRam-0 when running on PRU-0 and DRam-1 when
running on PRU-1 (default). In MM mode further memory is needed to
store the measurement data. Therefor libpruio uses the external memory
area.


DRam  {#SubDRam}
====

The following table shows the memory usage in the DRam area (DRam-0 for
PRU-0 or DRam-1 for PRU-1). Some context changes, depending on the
current driver function.

| Offset                               | Size                              | Mode   | Context                     |
| -----------------------------------: | :-------------------------------: | :----: | :-------------------------- |
| 0                                    | 4                                 | all    | Status                      |
| 4                                    | 4                                 | init   | offset ADC config           |
| 4                                    | 4                                 |  IO    | ball# config update         |
| PRUIO_TRG_PARA = 4                   | 28                                |  MM    | trigger parameters          |
| PRUIO_ADC_BUFF = 16                  | 16 * 2                            |  IO    | ADC sample values           |
| PRUIO_GPIO_OFFS = 64                 | 4 * PRUIO_GPIO_BLCK = 96          | all    | GPIO array                  |
| PRUIO_PIN_OFFS = 256                 | PRUIO_BALL_AZ + 1 = 110           | all    | PinConf array               |
| PRUIO_PIN_OFFS + PRUIO_BALL_AZ + 1   | 4 * PRUIO_GPIO_DATA = 80          | init   | Initial GPIO configuration  |
| PRUIO_PIN_OFFS + PRUIO_BALL_AZ + 1   |                                   |        |                             |
| + 4 * PRUIO_GPIO_DATA                | PRUIO_ADC_DATA or PRUIO_ADC_EMPTY | init   | initial ADC configuration   |
| PRUIO_PIN_OFFS + PRUIO_BALL_AZ + 1   | PRUIO_BALL_AZ + 1 = 110           | all    | PinGpio array               |
| PRUIO_ADC_OFFS = 512                 | OFFSETOF(PruIo, DRam) = 192       | config | ADC configuration           |
| PRUIO_ADC_OFFS = 512                 | (max) 2 * Samples * ChAz          |  MM    | sort buffer for pre-trigger |

Check file pruio.hp for the definition of the symbols in this table.


External Ram {#SubERam}
============

The external ram is used in MM mode to store the sampled data from the
ADC device. Currently, the number of samples in MM mode is limited by
the size of the external ram, which is a block of 256 kByte (by
default). You can customize the size of the external ram by setting an
option in the kernel driver call

~~~{.sh}
/sbin/modprobe uio_pruss extram_pool_sz=0x800000
~~~

The mximum size is 8 Mb.

In case of a pre-trigger the starting area of the erternal ram is used
as ring buffer. Its datas are invalid during measurement. Don't read
them before the function \ref PruIo::mm_start() finished.

The ring buffer gets sorted after measurement and libpruio shifts some
data to the DRam area, starting at offset &h200. In worst case, both
DRam areas are used for that purpose (depending on the fill level of
the ring buffer when the trigger event happens).
