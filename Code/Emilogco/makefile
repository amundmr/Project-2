CC = g++
CCFLAGS = -larmadillo -lblas -llapack -std=c++11 -O3

main: jacobi_rotate.o eig_solver.o max_offdiag.o
	$(CC) main.cpp jacobi_rotate.o eig_solver.o max_offdiag.o arma_eig.o $(CCFLAGS) -o main.exe

jacobi_rotate.o eig_solver.o max_offdiag.o:
	$(CC) $(CCFLAGS) jacobi_rotate.cpp eig_solver.cpp max_offdiag.cpp arma_eig.cpp -c

clean:
	rm -rf *.o main.exe