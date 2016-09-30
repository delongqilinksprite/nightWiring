/*
 * nightWiringSPI.h:
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

#ifdef __cplusplus
extern "C" {
#endif

int nightWiringSPIGetFd     (int channel) ;
int nightWiringSPIDataRW    (int channel, unsigned char *data, int len) ;
int nightWiringSPISetupMode (int channel, int speed, int mode) ;
int nightWiringSPISetup     (int channel, int speed) ;

#ifdef __cplusplus
}
#endif
