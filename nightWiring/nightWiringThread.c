/*
 * nightWiringThread.c:
 *	Provide a simplified interface to pthreads
 *
 *	Copyright (c) 2012 Gordon Henderson
 ***********************************************************************
 * This file is part of nightWiring:
 *	https://projects.drogon.net/raspberry-nightWiring/nightWiring/
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

#include <pthread.h>
#include "nightWiring.h"

static pthread_mutex_t nightWiringMutexes [4] ;



/*
 * nightWiringThreadCreate:
 *	Create and start a thread
 *********************************************************************************
 */

int nightWiringThreadCreate (void *(*fn)(void *))
{
  pthread_t myThread ;

  return pthread_create (&myThread, NULL, fn, NULL) ;
}

/*
 * nightWiringLock: nightWiringUnlock:
 *	Activate/Deactivate a mutex.
 *	We're keeping things simple here and only tracking 4 mutexes which
 *	is more than enough for out entry-level pthread programming
 *********************************************************************************
 */

void nightWiringLock (int key)
{
  pthread_mutex_lock (&nightWiringMutexes [key]) ;
}

void nightWiringUnlock (int key)
{
  pthread_mutex_unlock (&nightWiringMutexes [key]) ;
}

