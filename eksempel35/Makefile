#
# Makefile
#

OBJ = test/test.o \
	test/test_rektangel.o \
	test/test_lyd.o \
	konfigurasjon.o \
	logger.o \
	lyd.o \
	tekst.o \
	rektangel.o \
	ufoer.o \
	ufo.o \
	prosjektil.o \
	kanon.o \
	modell.o \
	skjerm.o \
	kontrollsentral.o \
	spaceinvader.o \
	main.o



CFLAGS = -g -Wall -pedantic -std=c11 -I/usr/include/

LDFLAGS = -L/bin/ -L/lib/

LIBS = -lmingw32 -mwindows -mconsole -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_mixer

CC = gcc

all:	SpaceInvader.exe

SpaceInvader.exe:	$(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS) $(LIBS)  

clean:
	rm *.o 
	rm test/*.o
	rm SpaceInvader.exe

test.o: test/test.c
	$(CC) $(CFLAGS) -c $< -o $@

test_rektangel.o: test/test_rektangel.c
	$(CC) $(CFLAGS) -c $< -o $@

test_lyd.o: test/test_lyd.c
	$(CC) $(CFLAGS) -c $< -o $@
