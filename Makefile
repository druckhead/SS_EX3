CC=gcc
CFLAGS= -Wall -g
EXE=stringProg


all: ${EXE}

stringProg: sequence.c sequence.h
	${CC} ${CFLAGS} $< -o $@

.PHONY: clean all

clean:
	rm -f *.o *.exe stringProg main 
run:
	./stringProg