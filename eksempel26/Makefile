all:	test.exe

test.exe:	spaceinvader.o main.o 
	gcc spaceinvader.o main.o -lmingw32 -mwindows -mconsole -lSDL2main -lSDL2 -o $@

main.o:	main.c
	gcc -Wall -c -I. -I/usr/include $< -o $@

spaceinvader.o:	spaceinvader.c
	gcc -Wall -c -I. -I/usr/include $< -o $@

clean:
	rm *.o