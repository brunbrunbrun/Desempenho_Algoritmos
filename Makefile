main: main.o busca_sequencial.o
	g++ main.o busca_sequencial.o -o main.exe

main.o: main.cpp header.h
	g++ main.cpp -c

busca_sequencial.o: busca_sequencial.cpp
	g++ busca_sequencial.cpp -c

clean:
	rm *.o
