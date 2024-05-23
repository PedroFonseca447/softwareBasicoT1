all: bibhardware.a tool

tool: registers.o bibhardware.a
gcc -o tool registers.o -bibhardware -L.

bibhardware.a: libregisters.o
      ar rcs bibhardware.a libregisters.o

registers.o: registers.c
      gcc -c register


bibhardware.o: libregisters.c
      gcc -c libregisters.c

clean :
  rm -f *.o tool *.a

