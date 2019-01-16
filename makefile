SHELL = /bin/sh
CC = icc -O3 -openmp
EXEC = princ
SRC = $(EXEC).c

OBJETS	= bf.o princ.o

all: $(EXEC)

$(EXEC): $(OBJETS)
	$(CC) -o princ $(OBJETS) -lm  -lcrypto

clean:
	rm -f *.o *~ .*~ > /dev/null

#########################################################################
#	Les cibles
#########################################################################

bf.o: bf.c bf.h 
	@echo "	Compilation de bf.c"
	@$(CC) $(OPTIONS) -c bf.c


princ.o: princ.c bf.h
	@echo "	Compilation de princ.c"
	@$(CC) $(OPTIONS) -c princ.c


