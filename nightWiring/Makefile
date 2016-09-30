#
# Makefile:
#	nightWiring - Wiring Compatable library for the Raspberry Pi
#
#	Copyright (c) 2012-2015 Gordon Henderson
#################################################################################
# This file is part of nightWiring:
#	https://projects.drogon.net/raspberry-pi/nightWiring/
#
#    nightWiring is free software: you can redistribute it and/or modify
#    it under the terms of the GNU Lesser General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    nightWiring is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU Lesser General Public License for more details.
#
#    You should have received a copy of the GNU Lesser General Public License
#    along with nightWiring.  If not, see <http://www.gnu.org/licenses/>.
#################################################################################

VERSION=$(shell cat ../VERSION)
DESTDIR?=/usr
PREFIX?=/local

LDCONFIG?=ldconfig

ifneq ($V,1)
Q ?= @
endif

STATIC=libnightWiring.a
DYNAMIC=libnightWiring.so.$(VERSION)

#DEBUG	= -g -O0
DEBUG	= -O2
CC	= gcc
INCLUDE	= -I.
DEFS	= -D_GNU_SOURCE
CFLAGS	= $(DEBUG) $(DEFS) -Wformat=2 -Wall -Winline $(INCLUDE) -pipe -fPIC

LIBS    =

###############################################################################

SRC	=		nightWiring.c								\
			nightWiringSerial.c							\
			nightWiringPriority.c nightWiringThread.c	\
			nightWiringSPI.c nightWiringI2C.c
#			nightWiringGPIO.c nightWiringShift.c		\
#			nightWiringSoftPwm.c nightWiringSoftTone.c 

HEADERS =	nightWiring.h								\
			nightWiringSerial.h							\
			nightWiringPriority.h nightWiringThread.h	\
			nightWiringSPI.h nightWiringI2C.h
#			nightWiringGPIO.h nightWiringShift.h		\
#			nightWiringSoftPwm.h nightWiringSoftTone.h


OBJ	=	$(SRC:.c=.o)

all:		$(DYNAMIC)

static:		$(STATIC)

$(STATIC):	$(OBJ)
	$Q echo "[Link (Static)]"
	$Q ar rcs $(STATIC) $(OBJ)
	$Q ranlib $(STATIC)
#	@size   $(STATIC)

$(DYNAMIC):	$(OBJ)
	$Q echo "[Link (Dynamic)]"
	$Q $(CC) -shared -Wl,-soname,libnightWiring.so$(nightWiring_SONAME_SUFFIX) -o libnightWiring.so.$(VERSION) -lpthread $(OBJ)

.c.o:
	$Q echo [Compile] $<
	$Q $(CC) -c $(CFLAGS) $< -o $@


.PHONY:	clean
clean:
	$Q echo "[Clean]"
	$Q rm -f $(OBJ) $(OBJ_I2C) *~ core tags Makefile.bak libnightWiring.*

.PHONY:	tags
tags:	$(SRC)
	$Q echo [ctags]
	$Q ctags $(SRC)


.PHONY:	install
install:	$(DYNAMIC)
	$Q echo "[Install Headers]"
	$Q install -m 0755 -d						$(DESTDIR)$(PREFIX)/include
	$Q install -m 0644 $(HEADERS)					$(DESTDIR)$(PREFIX)/include
	$Q echo "[Install Dynamic Lib]"
	$Q install -m 0755 -d						$(DESTDIR)$(PREFIX)/lib
	$Q install -m 0755 libnightWiring.so.$(VERSION)			$(DESTDIR)$(PREFIX)/lib/libnightWiring.so.$(VERSION)
	$Q ln -sf $(DESTDIR)$(PREFIX)/lib/libnightWiring.so.$(VERSION)	$(DESTDIR)/lib/libnightWiring.so
	$Q $(LDCONFIG)

.PHONY:	install-static
install-static:	$(STATIC)
	$Q echo "[Install Headers]"
	$Q install -m 0755 -d						$(DESTDIR)$(PREFIX)/include
	$Q install -m 0644 $(HEADERS)					$(DESTDIR)$(PREFIX)/include
	$Q echo "[Install Static Lib]"
	$Q install -m 0755 -d						$(DESTDIR)$(PREFIX)/lib
	$Q install -m 0755 libnightWiring.a					$(DESTDIR)$(PREFIX)/lib

.PHONY:	install-deb
install-deb:	$(DYNAMIC)
	$Q echo "[Install Headers: deb]"
	$Q install -m 0755 -d							~/nightWiring/debian-template/nightWiring/usr/include
	$Q install -m 0644 $(HEADERS)						~/nightWiring/debian-template/nightWiring/usr/include
	$Q echo "[Install Dynamic Lib: deb]"
	install -m 0755 -d							~/nightWiring/debian-template/nightWiring/usr/lib
	install -m 0755 libnightWiring.so.$(VERSION)				~/nightWiring/debian-template/nightWiring/usr/lib/libnightWiring.so.$(VERSION)
	ln -sf ~/nightWiring/debian-template/nightWiring/usr/lib/libnightWiring.so.$(VERSION)	~/nightWiring/debian-template/nightWiring/usr/lib/libnightWiring.so

.PHONY:	uninstall
uninstall:
	$Q echo "[UnInstall]"
	$Q cd $(DESTDIR)$(PREFIX)/include/ && rm -f $(HEADERS)
	$Q cd $(DESTDIR)$(PREFIX)/lib/     && rm -f libnightWiring.*
	$Q $(LDCONFIG)


.PHONY:	depend
depend:
	makedepend -Y $(SRC) $(SRC_I2C)


# Basic Modules
nightWiring.o: nightWiring.h

# GPIO Independent Modules
wiringSerial.o: nightWiringSrial.h
nightWiringSPI.o: nightWiring.h nightWiringSPI.h
nightWiringI2C.o: nightWiring.h nightWiringI2C.h

# System Dependent Modules
nightWiringPriority.o: nightWiring.h
nightWiringThread.o: nightWiring.h

# GPIO Dependent Modules
#nightWiringGPIO.o: nightWiringsoftPwm.h nightWiringsoftTone.h nightWiringGPIO.h nightWiring.h
#softPwm.o: nightWiring.h softPwm.h
#softTone.o: nightWiring.h softTone.h
#wiringShift.o: nightWiring.h nightWiringShift.h