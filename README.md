# Night Wiring

By Xiaohai Li (haixiaolee@gmail.com)

For now it's a cross-platform C lib to control the hardware interfaces including UART, I2C and SPI.
Most of the codes are from wiringPi.

Next step is implement GPIO funtion for RK3288 platform.

## Installation

```sh
cd nightWiring/
make -j4
sudo make install
```

## Programming

```C
//Including top level header
#include "nightWiring.h"
//Including header of each module by interface
#include "nightWiringSerial.h"
#include "nightWiringSPI.h"
#include "nightWiringI2C.h"
```

Refer to examples for details.