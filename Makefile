#CXX = gcc -Wno-implicit-int	#turn off thie specific warning message - not needed for the g++ compiler

prog1 : main.o hw4_functions.o
	$(CXX) main.o hw4_functions.o -o prog1

hw4.o: main.cpp
	$(CXX) -c main.cpp

hw4_functions.o: hw4_functions.cpp
	$(CXX) -c hw4_functions.cpp

clean:
	rm *.o prog*
