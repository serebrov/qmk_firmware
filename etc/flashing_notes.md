## Flashing Elite-C with dfu bootloader

```
qmk flash -kb boardsource/microdox -km cole -bl dfu
```

    Compiling keymap with make boardsource/microdox:cole:dfu


    QMK Firmware custom/2020-12-12-11-45-before
    WARNING:
     Can not run bin/qmk! This tool will be required when the develop branch is merged on 2020 Aug 29.

     Please run util/qmk_install.sh to install all the dependencies QMK requires.

    Making boardsource/microdox with keymap cole and target dfu

    avr-gcc (Homebrew AVR GCC 8.4.0) 8.4.0
    Copyright (C) 2018 Free Software Foundation, Inc.
    This is free software; see the source for copying conditions.  There is NO
    warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

    Size before:
       text	   data	    bss	    dec	    hex	filename
          0	  24456	      0	  24456	   5f88	.build/boardsource_microdox_cole.hex

    Copying boardsource_microdox_cole.hex to qmk_firmware folder                                        [OK]
    Checking file size of boardsource_microdox_cole.hex                                                 [OK]
     * The firmware size is fine - 24456/28672 (85%, 4216 bytes free)
    dfu-programmer: no device present.
    ERROR: Bootloader not found. Trying again in 5s.
    dfu-programmer: no device present.
    ERROR: Bootloader not found. Trying again in 5s.
    Bootloader Version: 0x00 (0)
    Erasing flash...  Success
    Checking memory from 0x0 to 0x6FFF...  Empty.
    0%                            100%  Programming 0x6000 bytes...
    [>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>]  Success
    0%                            100%  Reading 0x7000 bytes...
    [>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>]  Success
    Validating...  Success
    0x6000 bytes written into 0x7000 bytes memory (85.71%).
    Time: 0h:00m:16s

Note: without the `-bl dfu` parameter, nothing bad happens, it just waiting for the controller and can not find it.

Note: to reset the controller without the reset button, use RST and GND pins (there are two near each other on one side), connect them with tweezers.

## Flashing Pro Micro

New one, not flashed before - flashing whent on immediately, no reset was needed:

    <<<$ qmk flash -kb boardsource/microdox -km cole
    Ψ Compiling keymap with make boardsource/microdox:cole:flash


    QMK Firmware custom/2020-12-12-11-45-before
    WARNING:
     Can not run bin/qmk! This tool will be required when the develop branch is merged on 2020 Aug 29.

     Please run util/qmk_install.sh to install all the dependencies QMK requires.

    Making boardsource/microdox with keymap cole and target flash

    avr-gcc (Homebrew AVR GCC 8.4.0) 8.4.0
    Copyright (C) 2018 Free Software Foundation, Inc.
    This is free software; see the source for copying conditions.  There is NO
    warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

    Size before:
       text	   data	    bss	    dec	    hex	filename
          0	  24456	      0	  24456	   5f88	.build/boardsource_microdox_cole.hex

    Copying boardsource_microdox_cole.hex to qmk_firmware folder                                        [OK]
    Checking file size of boardsource_microdox_cole.hex                                                 [OK]
     * The firmware size is fine - 24456/28672 (85%, 4216 bytes free)
    Detecting USB port, reset your controller now..........................
    Device /dev/tty.usbmodem14201 has appeared; assuming it is the controller.
    Waiting for /dev/tty.usbmodem14201 to become writable.

    Connecting to programmer: .
    Found programmer: Id = "CATERIN"; type = S
        Software Version = 1.0; No Hardware Version given.
    Programmer supports auto addr increment.
    Programmer supports buffered memory access with buffersize=128 bytes.

    Programmer supports the following devices:
        Device code: 0x44

    avrdude: AVR device initialized and ready to accept instructions

    Reading | ################################################## | 100% 0.00s

    avrdude: Device signature = 0x1e9587 (probably m32u4)
    avrdude: NOTE: "flash" memory has been specified, an erase cycle will be performed
             To disable this feature, specify the -D option.
    avrdude: erasing chip
    avrdude: reading input file ".build/boardsource_microdox_cole.hex"
    avrdude: input file .build/boardsource_microdox_cole.hex auto detected as Intel Hex
    avrdude: writing flash (24456 bytes):

    Writing | ################################################## | 100% 1.84s

    avrdude: 24456 bytes of flash written
    avrdude: verifying flash memory against .build/boardsource_microdox_cole.hex:
    avrdude: load data flash data from input file .build/boardsource_microdox_cole.hex:
    avrdude: input file .build/boardsource_microdox_cole.hex auto detected as Intel Hex
    avrdude: input file .build/boardsource_microdox_cole.hex contains 24456 bytes
    avrdude: reading on-chip flash data:

    Reading | ################################################## | 100% 0.19s

    avrdude: verifying ...
    avrdude: 24456 bytes of flash verified

    avrdude: safemode: Fuses OK (E:CB, H:D8, L:FF)

    avrdude done.  Thank you.

On the next flash, the RST+GND reset was needed (as expected).
