all:	spaceinvader.exe

spaceinvader.exe:	kanon.o modell.o skjerm.o kontrollsentral.o spaceinvader.o main.o 
	gcc kanon.o modell.o skjerm.o kontrollsentral.o spaceinvader.o main.o -lmingw32 -mwindows -mconsole -lSDL2main -lSDL2 -o $@

kanon.o:	kanon.c
	gcc -Wall -c -I. -I/usr/include $< -o $@

main.o:	main.c
	gcc -Wall -c -I. -I/usr/include $< -o $@

spaceinvader.o:	spaceinvader.c
	gcc -Wall -c -I. -I/usr/include $< -o $@

modell.o:	modell.c
	gcc -Wall -c -I. -I/usr/include $< -o $@

skjerm.o:	skjerm.c
	gcc -Wall -c -I. -I/usr/include $< -o $@

kontrollsentral.o:	kontrollsentral.c
	gcc -Wall -c -I. -I/usr/include $< -o $@
	
clean:
	rm *.o 
	rm spaceinvader.exe