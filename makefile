main: thalia_ysassi_project1.o
	g++ thalia_ysassi_project1.o -o main

thalia.ysassi-project1.o: thalia_ysassi_project1.cpp
	g++ -c thalia_ysassi_project1.cpp

clean:
	rm *.o main
