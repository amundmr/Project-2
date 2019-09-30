
# Comment lines
# General makefile for c++ - choose PROG =   name of given program
# Here we define compiler option, libraries and the  target
CPPflags= g++ -O3
# Here we define the library functions we nee
LIB = -larmadillo -llapack -lblas
# Here we define the name of the executable
PROG= test.exe
${PROG} :	   	test_main.o  test_func.o Jacobi_method.o off.o Jacobi_rotate.o
		${CPPflags} test_main.o test_func.o Jacobi_method.o off.o Jacobi_rotate.o ${LIB} -o ${PROG}

test_main.o :			test_main.cpp
						${CPPflags} -c test_main.cpp

test_func.o :			test_func.cpp
						${CPPflags} -c test_func.cpp

Jacobi_method.o :		../functions/Jacobi_method.cpp
						${CPPflags} -c ../functions/Jacobi_method.cpp

Jacobi_rotate.o :		../functions/Jacobi_rotate.cpp
						${CPPflags} -c ../functions/Jacobi_rotate.cpp

off.o :		../functions/off.cpp
						${CPPflags} -c ../functions/off.cpp
