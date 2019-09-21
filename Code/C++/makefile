CC = g++
CCFLAGS = -larmadillo -llapack -lblas -std=c++14

main.exe: obj
	g++ main.cpp $(wildcard obj/*.o) $(CCFLAGS) -o main.exe

obj: 
	mkdir obj/; \
	cd functions; \
	g++ -c *.cpp; \
	mv *.o ../obj; \

clean:
	rm -rf obj/ main.exe