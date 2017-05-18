all: Program1.1 Program1.2 Program1.3

%: %.cc
	g++ -std=c++11 $< -o ./bin/$@

