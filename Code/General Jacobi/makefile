CC = g++
CCFLAGS = -larmadillo -lblas -llapack -std=c++11 -O3

main: obj
	$(CC) $(wildcard *.o) main.cpp $(CCFLAGS) -o main.exe

obj:
	$(CC) $(CCFLAGS) $(wildcard ../Functions/*.cpp) -c

clean:
	rm -rf *.o main.exe