CXX=g++

CXXFLAGS= -std=c++11 -Wall -g

test: lab04Test.cpp WordCount.cpp tddFuncs.cpp
	g++ -std=c++11 lab04Test.cpp WordCount.cpp tddFuncs.cpp -o test

runtests: test
	./test

clean:
	/bin/rm -f test WordCount *.o
