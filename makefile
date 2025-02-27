main: Thalia_Ysassi_Project1.o
	g++ Thalia_Ysassi_Project1.o -o main

Thalia_Ysassi_Project1.o: Thalia_Ysassi_Project1.cpp
	g++ -c Thalia_Ysassi_Project1.cpp

clean:
	rm *.o main
