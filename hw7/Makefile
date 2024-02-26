all: hex2raw problem1 problem2 problem3

hex2raw: hex2raw.cpp
	g++ $^ -o $@

problem%: problem%.cpp
	g++ -std=c++11 -g -fno-stack-protector $^ -o $@

clean:
	rm -rf hex2raw problem1 problem2 problem3 *.dSYM
