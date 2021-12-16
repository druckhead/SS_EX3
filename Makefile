CC=gcc
AR=ar -rcs
CFLAGS= -Wall -g
EXE=stringProg


all: ${EXE}

stringProg: main.c seqlib.a sequence.h
	${CC} ${CFLAGS} -o ${EXE} main.c seqlib.a

seqlib.a: sequence.o seq_helper.o
	${AR} seqlib.a sequence.o seq_helper.o

sequence.o: sequence.c seq_helper.c seq_helper.h
	${CC} ${CFLAGS} -c sequence.c seq_helper.c

seq_helper.o: seq_helper.c seq_helper.h
	${CC} ${CFLAGS} -c seq_helper.c

.PHONY: clean all main

clean: 
	rm -f *.o *.a stringProg
run:
	./stringProg