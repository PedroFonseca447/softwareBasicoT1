# Regras principais
all: tool

tool: biblioteca.o libregisters.a
	gcc -o tool biblioteca.o -lregisters -L.

libregisters.a: biblioteca.o
	ar rcs libregisters.a biblioteca.o

biblioteca.o: biblioteca.c libregisters.h
	gcc -c biblioteca.c

# Limpeza dos arquivos gerados
clean:
	rm -f *.o tool *.a
