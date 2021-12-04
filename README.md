## divergence-meter-clock
Arduino-based Centisecond Clock

This is a Steins-Gate inspired Clock that uses the DS3231-RTC Module and two 4x7 Segment Displays

An Arduino Mega 2560 was used for this Project but the Code should run on almost any Arduino-Device with enough pins

![grafik](https://user-images.githubusercontent.com/53939068/144712973-d272cdf8-56fe-4b63-a4cd-f548dc0fd3c2.png)

Required Libraries
- DS3231-RTC Library <DS3231.h>
- Seven-Segment Display Library <SevSeg.h>
- Wire-Library <Wire.h> (for I2C Communication) 

Please refer to the Datasheet of your specific 4x7-Segment Display since wiring might vary !

Clock.ino contains the Code to display the currect time of the DS3231 Module
!To set the time refer to the ds3231 library and upload the "DS3231_set.ino" Code while following it's instructions!

Two-Extra LED's are optional but switch randomly every 24h (at 00:00) -> show Alpha/Beta-timeline

Feel free to modify/use the code as you like
