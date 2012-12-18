
CFLAGS=-O2 -Wall

# JTAGISO
CFLAGS += -DJTAGISO

# JTAGTINY
#CFLAGS += -DJTAGTINY

## -lftd2xx -L/usr/local/lib
## ftd2xx_dll.h

all: ftd2xx.dll.so libftd2xx.def siusbxp.dll.so libSiUSBXp.def

# Olimex -ISO
ftd2xx.o: ftd2xx_main.c ftd2xx.h 
	winegcc -c -D_REENTRANT -D__WINESRC__ $(CFLAGS) -o ftd2xx.o $<

ftd2xx.dll.so: ftd2xx.o ftd2xx.spec
	winegcc $(CFLAGS) -L. -lntdll -lkernel32 -o ftd2xx.dll $< -shared ftd2xx.spec

libftd2xx.def: ftd2xx.spec ftd2xx.dll.so
	winebuild -w --export $< --def -o libftd2xx.def

# Olimex -TINY
SiUSBXp.o: SiUSBXp_main.c SiUSBXp_dll.h
	winegcc -c -D_REENTRANT -D__WINESRC__ $(CFLAGS) -o SiUSBXp.o $<

siusbxp.dll.so: SiUSBXp.o SiUSBXp.spec
	winegcc $(CFLAGS) -L. -lntdll -lkernel32 -o siusbxp.dll $< -shared SiUSBXp.spec

libSiUSBXp.def: SiUSBXp.spec siusbxp.dll.so
	winebuild -w --export $< --def -o libSiUSBXp.def

#
install: ftd2xx.dll.so siusbxp.dll.so
	install -v ftd2xx.dll.so /usr/lib/wine/
	install -v siusbxp.dll.so /usr/lib/wine/

clean:
	-rm -f ftd2xx.o ftd2xx.dll.so libftd2xx.def SiUSBXp.o siusbxp.dll.so libSiUSBXp.def

