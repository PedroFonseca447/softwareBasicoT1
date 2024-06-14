# Regras principais
all: tool

tool: registers.o biblioteca.o libregisters.a
	gcc -o tool registers.o biblioteca.o -lregisters -L.

libregisters.a: registers.o
	ar rcs libregisters.a registers.o

registers.o: registers.c libregisters.h
	gcc -c registers.c

biblioteca.o: biblioteca.c biblioteca.o
	gcc -c biblioteca.c

# Limpeza dos arquivos gerados
clean:
	rm -f *.o tool *.a
