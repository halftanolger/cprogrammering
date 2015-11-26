all:	Test.exe

Test.exe:	test.o 
	gcc test.o -o $@

test.o:	test.c
	gcc -c $< -o $@
	
clean:
	rm *.o 
	rm Test.exe
		