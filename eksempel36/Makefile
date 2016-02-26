
CC = gcc

CFLAGS = -Wall -std=c99 -g -c 

INCLUDES = -I/usr/include/SDL2

LIBS = -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_mixer

all:	bin/SpaceInvader.exe

bin/SpaceInvader.exe:	test.o test_lyd.o test_rektangel.o konfigurasjon.o logger.o tekst.o lyd.o rektangel.o ufoer.o ufo.o prosjektil.o kanon.o modell.o skjerm.o kontrollsentral.o spaceinvader.o main.o 
	gcc test.o test_lyd.o test_rektangel.o konfigurasjon.o logger.o tekst.o lyd.o rektangel.o ufo.o ufoer.o prosjektil.o kanon.o modell.o skjerm.o kontrollsentral.o spaceinvader.o main.o $(LIBS) -o $@

test.o:	test/test.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

test_rektangel.o:  test/test_rektangel.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

test_lyd.o:   test/test_lyd.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

konfigurasjon.o:	konfigurasjon.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@
    
tekst.o:	tekst.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

lyd.o:	lyd.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

logger.o:	logger.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@
    
rektangel.o:	rektangel.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

ufo.o:	ufo.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

ufoer.o:	ufoer.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@
	
prosjektil.o:	prosjektil.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

kanon.o:	kanon.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

main.o:	main.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

spaceinvader.o:	spaceinvader.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

modell.o:	modell.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

skjerm.o:	skjerm.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

kontrollsentral.o:	kontrollsentral.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm *.o 
	rm bin\SpaceInvader*
	rm test\*.o
