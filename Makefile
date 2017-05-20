all: Program1.1 Program1.2 Program1.3 Program1.4 Exercise1.16

%: %.cc
	g++ -std=c++11 $< -o ./bin/$@

