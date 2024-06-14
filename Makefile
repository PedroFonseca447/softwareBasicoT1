# Regras principais
all: tool

tool: main.o registers.o libregisters.a
	gcc -o tool  registers.o -lregisters -L.

libregisters.a: registers.o
	ar rcs libregisters.a registers.o

registers.o: registers.c libregisters.h
	gcc -c registers.c

# Limpeza dos arquivos gerados
clean:
	rm -f *.o tool *.a
