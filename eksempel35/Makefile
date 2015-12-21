
CC = gcc

CFLAGS = -Wall -std=c99 -c

INCLUDES = 

all:	bin/SpaceInvader.exe

bin/SpaceInvader.exe:	test/test.o test/test_lyd.o test/test_rektangel.o konfigurasjon.o logger.o tekst.o lyd.o rektangel.o ufoer.o ufo.o prosjektil.o kanon.o modell.o skjerm.o kontrollsentral.o spaceinvader.o main.o 
	gcc test/test.o test/test_lyd.o test/test_rektangel.o konfigurasjon.o logger.o tekst.o lyd.o rektangel.o ufo.o ufoer.o prosjektil.o kanon.o modell.o skjerm.o kontrollsentral.o spaceinvader.o main.o -lmingw32 -mwindows -mconsole -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_mixer -o $@

test/test.o:	test/test.c
	$(CC) $(CFLAGS) $< -o $@

test/test_rektangel.o:  test/test_rektangel.c
	$(CC) $(CFLAGS) $< -o $@

test/test_lyd.o:   test/test_lyd.c
	$(CC) $(CFLAGS) $< -o $@

konfigurasjon.o:	konfigurasjon.c
	$(CC) $(CFLAGS) $< -o $@
    
tekst.o:	tekst.c
	$(CC) $(CFLAGS) $< -o $@

lyd.o:	lyd.c
	$(CC) $(CFLAGS) $< -o $@

logger.o:	logger.c
	$(CC) $(CFLAGS) $< -o $@
    
rektangel.o:	rektangel.c
	$(CC) $(CFLAGS) $< -o $@

ufo.o:	ufo.c
	$(CC) $(CFLAGS) $< -o $@

ufoer.o:	ufoer.c
	$(CC) $(CFLAGS) $< -o $@
	
prosjektil.o:	prosjektil.c
	$(CC) $(CFLAGS) $< -o $@

kanon.o:	kanon.c
	$(CC) $(CFLAGS) $< -o $@

main.o:	main.c
	$(CC) $(CFLAGS) $< -o $@

spaceinvader.o:	spaceinvader.c
	$(CC) $(CFLAGS) $< -o $@

modell.o:	modell.c
	$(CC) $(CFLAGS) $< -o $@

skjerm.o:	skjerm.c
	$(CC) $(CFLAGS) $< -o $@

kontrollsentral.o:	kontrollsentral.c
	$(CC) $(CFLAGS) $< -o $@
	
clean:
	del *.o 
	del test\*.o
	del SpaceInvader.exe