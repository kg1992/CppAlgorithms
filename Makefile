1: Program1.1 Program1.2 Program1.3 Program1.4 Exercise1.16
2: Program2.1 Program2.2
3: Program3.2 Program3.5

cc= g++
cflags=-std=c++11 -O -Wall -Wextra -Werror -ansi -pedantic -c
srcdir=./src/
objdir=./obj/
bindir=./bin/
rm=rm\

$(objdir)Helper.o:
	$(cc) $(cflags) $(srcdir)Helper.cc -o $@

$(objdir)%.o: $(srcdir)%.cc
	$(cc) $(cflags) $< -o $@

%: $(objdir)%.o $(objdir)Helper.o
	$(cc) -std=c++11 $< $(objdir)Helper.o -o $(bindir)$@

clean:
	$(rm) ./obj/*
	$(rm) ./bin/*