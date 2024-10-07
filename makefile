output: main.o simple_atm_controller.o
	g++ -std=c++0x -Wall main.o simple_atm_controller.o -o output

main.o: main.cpp 
	g++ -c main.cpp

simple_atm_controller.o: simple_atm_controller.cpp simple_atm_controller.h
	g++ -c simple_atm_controller.cpp

clean:
	rm *.o output
