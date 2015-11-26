all:	SpaceInvader.exe

SpaceInvader.exe:	spaceinvader.o main.o 
	gcc spaceinvader.o main.o -o $@

spaceinvader.o:	spaceinvader.c
	gcc -c $< -o $@

main.o:	main.c
	gcc -c $< -o $@
	
clean:
	rm *.o 
	rm SpaceInvader.exe
		