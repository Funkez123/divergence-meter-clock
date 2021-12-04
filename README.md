## divergence-meter-clock
Arduino-based Centisecond Clock

This is a Steins-Gate inspired clock that uses the DS3231-RTC module and two 4x7 segment displays

An Arduino Mega 2560 was used for this Project but the code should run on almost any Arduino-Device with enough pins

![grafik](https://user-images.githubusercontent.com/53939068/144712973-d272cdf8-56fe-4b63-a4cd-f548dc0fd3c2.png)

Required Libraries
- DS3231-RTC Library <DS3231.h>
- Seven-Segment Display Library <SevSeg.h>
- Wire-Library <Wire.h> (for I2C Communication) 

Please refer to the datasheet of your specific 4x7-segment display since wiring might vary !

Clock.ino contains the code to display the currect time of the DS3231 module
!To set the time refer to the ds3231 library and upload the "DS3231_set.ino" code while following it's instructions!

Two-Extra LED's are optional but switch randomly every 24h (at 00:00) -> show Alpha/Beta-timeline

Feel free to modify/use the code as you like
