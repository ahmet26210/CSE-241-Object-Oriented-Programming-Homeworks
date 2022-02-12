output:	main.o 1801042674.o
	g++ -std=c++11 main.o 1801042674.o -o output
main.o:	main.cpp
	g++ -std=c++11 -c main.cpp
1801042674.o:1801042674.cpp pack.h
	g++ -std=c++11 -c 1801042674.cpp 
clean:
	rm *.o output
