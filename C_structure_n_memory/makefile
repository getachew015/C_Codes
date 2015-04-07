all: InvoiceDB

InvoiceDB: Main.o Invoice_Records.o
	gcc -o InvoiceDB Invoice_Records.o Main.o

Invoice_Records.o: Invoice_Records.c Invoice_Header.h
	gcc -c Invoice_Records.c

Main.o: Main.c Invoice_Header.h
	gcc -c Main.c

 
clean:
	rm InvoiceDB Main.o Invoice_Records.o
