
CFLAGS = -Wall -std=c99

INCLUDES = -I/usr/include -I/usr/local/includes -I

all:	SpaceInvader.exe

SpaceInvader.exe:	test/test.o test/test_rektangel.o tekst.o rektangel.o ufoer.o ufo.o prosjektil.o kanon.o modell.o skjerm.o kontrollsentral.o spaceinvader.o main.o 
	gcc test/test.o test/test_rektangel.o tekst.o rektangel.o ufo.o ufoer.o prosjektil.o kanon.o modell.o skjerm.o kontrollsentral.o spaceinvader.o main.o -lmingw32 -mwindows -mconsole -lSDL2main -lSDL2 -lSDL2_ttf -o $@

test/test.o:	test/test.c
	gcc -Wall -c -I/usr/include $< -o $@

test/test_rektangel.o:	test/test_rektangel.c
	gcc -Wall -c -I/usr/include $< -o $@

tekst.o:	tekst.c
	gcc $(CFLAGS) $(INCLUDES) -c $< -o $@

rektangel.o:	rektangel.c
	gcc -Wall -c -I/usr/include $< -o $@

ufo.o:	ufo.c
	gcc -Wall -c -I/usr/include $< -o $@

ufoer.o:	ufoer.c
	gcc -Wall -c -I/usr/include $< -o $@
	
prosjektil.o:	prosjektil.c
	gcc -Wall -c -I/usr/include $< -o $@

kanon.o:	kanon.c
	gcc -Wall -c -I/usr/include $< -o $@

main.o:	main.c
	gcc -Wall -c -I/usr/include $< -o $@

spaceinvader.o:	spaceinvader.c
	gcc -Wall -c -I/usr/include $< -o $@

modell.o:	modell.c
	gcc -Wall -c -I/usr/include $< -o $@

skjerm.o:	skjerm.c
	gcc -Wall -c -I/usr/include $< -o $@

kontrollsentral.o:	kontrollsentral.c
	gcc -Wall -c -I/usr/include $< -o $@
	
clean:
	rm *.o 
	rm test/*.o
	rm SpaceInvader.exe