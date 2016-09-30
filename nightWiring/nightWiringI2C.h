/*
 * i2c.h:
 *	Simplified I2C access routines
 *	Copyright (c) 2013 Gordon Henderson
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

extern int i2cRead           (int fd) ;
extern int i2cReadReg8       (int fd, int reg) ;
extern int i2cReadReg16      (int fd, int reg) ;

extern int i2cWrite          (int fd, int data) ;
extern int i2cWriteReg8      (int fd, int reg, int data) ;
extern int i2cWriteReg16     (int fd, int reg, int data) ;

extern int i2cSetupInterface (const char *device, int devId) ;
extern int i2cSetup (const char *device, const int devId);

#ifdef __cplusplus
}
#endif
