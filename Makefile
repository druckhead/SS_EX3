CC=gcc
AR=ar -rcs
CFLAGS= -Wall -g
EXE=stringProg


all: ${EXE}

stringProg: main.c seqlib.a
	${CC} ${CFLAGS} -o ${exe} $< seqlib.a

seqlib.a: seq_lib.o
	${AR} seqlib.a $<

seqlib,o: seq_lib.c seq_lib.h
	${CC} ${CFLAGS} -c #< -o seqlib.o

.PHONY: clean all main

clean: 
	rm -f *.o *.a *.exe stringProg
run:
	./stringProg