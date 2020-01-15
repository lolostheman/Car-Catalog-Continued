#CXX = gcc -Wno-implicit-int	#turn off thie specific warning message - not needed for the g++ compiler

prog1 : hw1.o hw1_functions.o
	$(CXX) hw1.o hw1_functions.o -o prog1

hw1.o: hw1.cpp
	$(CXX) -c hw1.cpp

hw1_functions.o: hw1_functions.cpp
	$(CXX) -c hw1_functions.cpp

clean:
	rm *.o prog*
