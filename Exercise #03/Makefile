3: main.o ProgrammingLanguage.o
	g++ -Wall main.o ProgrammingLanguage.o -o 3
main.o: main.cpp ProgrammingLanguage.h
	g++ -Wall -c main.cpp -o main.o
ProgrammingLanguage.o: ProgrammingLanguage.cpp ProgrammingLanguage.h
	g++ -Wall -c ProgrammingLanguage.cpp -o ProgrammingLanguage.o