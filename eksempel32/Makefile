﻿all:	SpaceInvader.exe

SpaceInvader.exe:	test/test.o test/test_rektangel.o rektangel.o ufoer.o ufo.o prosjektil.o kanon.o modell.o skjerm.o kontrollsentral.o spaceinvader.o main.o 
	gcc test/test.o test/test_rektangel.o rektangel.o ufo.o ufoer.o prosjektil.o kanon.o modell.o skjerm.o kontrollsentral.o spaceinvader.o main.o -lmingw32 -mwindows -mconsole -lSDL2main -lSDL2 -o $@

test/test.o:	test/test.c
	gcc -c -I/usr/include $< -o $@

test/test_rektangel.o:	test/test_rektangel.c
	gcc -c -I/usr/include $< -o $@

rektangel.o:	rektangel.c
	gcc -c -I/usr/include $< -o $@

ufo.o:	ufo.c
	gcc -c -I/usr/include $< -o $@

ufoer.o:	ufoer.c
	gcc -c -I/usr/include $< -o $@
	
prosjektil.o:	prosjektil.c
	gcc -c -I/usr/include $< -o $@

kanon.o:	kanon.c
	gcc -c -I/usr/include $< -o $@

main.o:	main.c
	gcc -c -I/usr/include $< -o $@

spaceinvader.o:	spaceinvader.c
	gcc -c -I/usr/include $< -o $@

modell.o:	modell.c
	gcc -c -I/usr/include $< -o $@

skjerm.o:	skjerm.c
	gcc -c -I/usr/include $< -o $@

kontrollsentral.o:	kontrollsentral.c
	gcc -c -I/usr/include $< -o $@
	
clean:
	rm *.o 
	rm test/*.o
	rm SpaceInvader.exe