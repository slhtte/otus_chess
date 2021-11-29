FigureSteps: main.o Tester.o FigureSteps.o
	g++ -std=c++11 -o FigureSteps main.o Tester.o FigureSteps.o
main.o: main.cc
	g++ -std=c++11 -c -o  main.o -g main.cc
Tester.o: Tester.cc
	g++ -std=c++11 -c -o Tester.o -g Tester.cc
FigureSteps.o: FigureSteps.cc
	g++ -std=c++11 -c -o FigureSteps.o -g FigureSteps.cc
