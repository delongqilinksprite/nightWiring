/*
 * nightWiring.h:
 *	Arduino like Wiring library for the Raspberry Pi.
 *	Copyright (c) 2012-2016 Gordon Henderson
 ***********************************************************************
 * This file is part of nightWiring:
 *	https://projects.drogon.net/raspberry-pi/nightWiring/
 *
 *    nightWiring is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    nightWiring is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public License
 *    along with nightWiring.  If not, see <http://www.gnu.org/licenses/>.
 ***********************************************************************
 */

#ifndef	__NIGHT_WIRING_H__
#define	__NIGHT_WIRING_H__

// C doesn't have true/false by default and I can never remember which
//	way round they are, so ...

#ifndef	TRUE
#  define	TRUE	(1==1)
#  define	FALSE	(!TRUE)
#endif

// Handy defines

// Threads

#define	NW_THREAD(X)	void *X (void *dummy)

// Failure modes

#define	NW_FATAL	(1==1)
#define	NW_ALMOST	(1==2)



// Function prototypes
//	c++ wrappers thanks to a comment by Nick Lott
//	(and others on the Raspberry Pi forums)

#ifdef __cplusplus
extern "C" {
#endif

// Data

// Internal

extern int nightWiringFailure (int fatal, const char *message, ...) ;

// Threads

extern int  nightWiringThreadCreate      (void *(*fn)(void *)) ;
extern void nightWiringLock              (int key) ;
extern void nightWiringUnlock            (int key) ;

// Schedulling priority

extern int nightWiringSetPri (const int pri) ;

// Extras from arduino land

extern void         delay             (unsigned int howLong) ;
extern void         delayMicroseconds (unsigned int howLong) ;
extern unsigned int millis            (void) ;
extern unsigned int micros            (void) ;

#ifdef __cplusplus
}
#endif

#endif
