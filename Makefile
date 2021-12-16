CC=gcc
AR=ar -rcs
CFLAGS= -Wall -g
EXE=stringProg


all: ${EXE}

stringProg: main.c seqlib.a
	${CC} ${CFLAGS} -o ${EXE} $?

seqlib.a: seq_helper.o sequence.o
	${AR} seqlib.a $?

sequence.o: sequence.c seq_helper.o
	${CC} ${CFLAGS} -c $<

seq_helper.o: seq_helper.c seq_helper.h
	${CC} ${CFLAGS} -c $<

.PHONY: clean all main

clean: 
	rm -f *.o *.a stringProg
run:
	./stringProg