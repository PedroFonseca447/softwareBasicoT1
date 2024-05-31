# Regras principais
all: tool

tool: registers.o bibhardware.a
	gcc -o tool registers.o -lregisters -L.

bibhardware.a: registers.o
	ar rcs bibhardware.a registers.o

registers.o: registers.c libregisters.h
	gcc -c registers.c



# Limpeza dos arquivos gerados
clean:
	rm -f *.o tool *.a
