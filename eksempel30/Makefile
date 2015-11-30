all:	SpaceInvader.exe

SpaceInvader.exe:	rektangel.o ufo.o prosjektil.o kanon.o modell.o skjerm.o kontrollsentral.o spaceinvader.o main.o 
	gcc rektangel.o ufo.o prosjektil.o kanon.o modell.o skjerm.o kontrollsentral.o spaceinvader.o main.o -lmingw32 -mwindows -mconsole -lSDL2main -lSDL2 -o $@

rektangel.o:	rektangel.c
	gcc -c -I/usr/include $< -o $@

ufo.o:	ufo.c
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
	rm SpaceInvader.exe