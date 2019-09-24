CC = g++ # compiler of choice
CCFLAGS = -larmadillo -llapack -lblas -std=c++11 # flags

main.exe: obj # target is to produce main.exe, but depends on obj function defined below.
	g++ main.cpp $(wildcard obj/*.o) $(CCFLAGS) -o main.exe
# takes every object-file in the folder obj and links them into the executable main.exe

obj: # main.exe's dependency. Creates a directory obj, compiles every .cpp in dir function and moves the .o-files to obj.
	mkdir obj/; \
	cd functions; \
	g++ -c $(CCFLAGS) *.cpp; \
	mv *.o ../obj; \

clean: # removes the object files and the executable.
	rm -rf obj/ main.exe