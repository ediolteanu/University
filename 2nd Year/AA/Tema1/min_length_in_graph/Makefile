C = g++
CFLAGS = -Wall -Wextra -O2
LDLIBS = -lm

run:
	./test_algo1	
	./test_algo2
	./test_algo3

run_bellman-ford_negatives:
	./test_bellman-ford_negatives

build: build_algo1 build_algo2 build_algo3

build_algo1: algo1.o test.o
	g++ algo1.o test.o -o test_algo1 $(CFLAGS)

build_algo2: algo2.o test.o
	g++ algo2.o test.o -o test_algo2 $(CFLAGS)

build_bellman-ford_negatives: algo3.o test_bellman-ford_negatives.o
	g++ algo3.o test_bellman-ford_negatives.o -o test_bellman-ford_negatives $(CFLAGS)
	
build_algo3: algo3.o test.o
	g++ algo3.o test.o -o test_algo3 $(CFLAGS)			

algo1.o: algo1.cpp
	g++ algo1.cpp -c $(CFLAGS)

algo2.o: algo2.cpp
	g++ algo2.cpp -c $(CFLAGS)	

algo3.o: algo3.cpp
	g++ algo3.cpp -c $(CFLAGS)

test.o: test.cpp
	g++ test.cpp -c $(CFLAGS)

test_bellman-ford_negatives.o: test_bellman-ford_negatives.cpp
	g++ test_bellman-ford_negatives.cpp -c $(CFLAGS)
.PHONY: clean
clean:
	rm -rf *.o test_algo1 test_algo2 test_algo3
	rm -rf test_bellman-ford_negatives
