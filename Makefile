c1all: Program1.1 Program1.2 Program1.3 Program1.4 Exercise1.16
c2all: Program2.1

cc= g++
cflags=-std=c++11 -O -Wall -Wextra -Werror -ansi -pedantic -c
srcdir=./src/
objdir=./obj/
bindir=./bin/
rm=rm\

1: c1all
2: c2all

$(objdir)Helper.o:
	$(cc) $(cflags) $(srcdir)Helper.cc -o $@

$(objdir)%.o: $(srcdir)%.cc
	$(cc) $(cflags) $< -o $@

%: $(objdir)%.o $(objdir)Helper.o
	$(cc) -std=c++11 $< $(objdir)Helper.o -o $(bindir)$@

clean:
	$(rm) ./obj/*
	$(rm) ./bin/*