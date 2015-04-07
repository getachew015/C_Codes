all: 3DArrays

3DArrays: ShippedOut.o
	gcc -o 3DArrays ShippedOut.o

ShippedOut.o: ShippedOut.c myData.h
	gcc -c ShippedOut.c

 
clean:
	rm 3DArrays ShippedOut.o
