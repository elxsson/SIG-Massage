all:
	gcc -c -Wall *.h
	gcc -c -Wall *.c
	gcc -o sig-massage *.o

clean:
	rm -f *.o *.gch sig-massage
