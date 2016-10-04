/*
 * spi.c:
 *	Simplified SPI access routines
 *	Copyright (c) 2012-2015 Gordon Henderson
 ***********************************************************************
 * This file is part of nightWiring:
 *	https://projects.drogon.net/raspberry-pi/nightWiring/
 *
 *    nightWiring is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as
 *    published by the Free Software Foundation, either version 3 of the
 *    License, or (at your option) any later version.
 *
 *    nightWiring is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with nightWiring.
 *    If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************
 */


#include <stdint.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>

#include "nightWiring.h"
#include "nightWiringSPI.h"


// The SPI bus parameters
const static uint8_t     spiBPW   = 8 ;
const static uint16_t    spiDelay = 0 ;

/*
 * spiDataRW:
 *	Write and Read a block of data over the SPI bus.
 *	Note the data ia being read into the transmit buffer, so will
 *	overwrite it!
 *	This is also a full-duplex operation.
 *********************************************************************************
 */

int spiDataTransfer (int fd, unsigned char *data, int len)
{
  struct spi_ioc_transfer spiMsg ;

  memset (&spiMsg, 0, sizeof (spiMsg)) ;

  spiMsg.tx_buf        = (unsigned long)data ;
  spiMsg.rx_buf        = (unsigned long)data ;
  spiMsg.len           = len ;
  spiMsg.delay_usecs   = spiDelay ;
  spiMsg.bits_per_word = spiBPW ;

  return ioctl (fd, SPI_IOC_MESSAGE(1), &spiMsg) ;
}


/*
 * spiSetupMode:
 *	Open the SPI device, and set it up, with the mode, etc.
 *********************************************************************************
 */

int spiSetupMode (const char *spidev, int speed, int mode)
{
  int fd ;

  mode    &= 3 ;	// Mode is 0, 1, 2 or 3
  if ((fd = open (spidev, O_RDWR)) < 0)
    return nightWiringFailure (NW_ALMOST, "Unable to open SPI device: %s\n", strerror (errno)) ;

// Set SPI parameters.

  if (ioctl (fd, SPI_IOC_WR_MODE, &mode)            < 0)
    return nightWiringFailure (NW_ALMOST, "SPI Mode Change failure: %s\n", strerror (errno)) ;
  
  if (ioctl (fd, SPI_IOC_WR_BITS_PER_WORD, &spiBPW) < 0)
    return nightWiringFailure (NW_ALMOST, "SPI BPW Change failure: %s\n", strerror (errno)) ;

  if (ioctl (fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed)   < 0)
    return nightWiringFailure (NW_ALMOST, "SPI Speed Change failure: %s\n", strerror (errno)) ;

  return fd ;
}


/*
 * spiSetup:
 *	Open the SPI device, and set it up, etc. in the default MODE 0
 *********************************************************************************
 */

int spiSetup (const char *spidev, int speed)
{
  return spiSetupMode (spidev, speed, 0) ;
}
