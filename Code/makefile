CC = g++
CCFLAGS = -larmadillo -lblas -llapack -std=c++11 -O3

main: obj
	$(CC) $(wildcard *.o) main_rho.cpp $(CCFLAGS) -o main_rho.exe

obj:
	$(CC) $(CCFLAGS) $(wildcard ./functions/*.cpp) -c

clean:
	rm -rf *.o main.exe
