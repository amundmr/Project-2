CC = g++
CFLAGS = -larmadillo -llapack -lblas -std=c++11

main: obj
	$(CC) $(wildcard *.o) bisection.cpp $(CCFLAGS) -o bisection.exe

obj:
	$(CC) $(CCFLAGS) $(wildcard ../Jacobi_method/*.cpp) -c

clean:
	rm -rf *.o bisection.exe
