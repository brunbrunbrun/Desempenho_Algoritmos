main: main.o busca_sequencial.o busca_binaria.o
	g++ main.o busca_sequencial.o busca_binaria.o -o main.exe

main.o: main.cpp header.h
	g++ main.cpp -c

busca_sequencial.o: busca_sequencial.cpp
	g++ busca_sequencial.cpp -c

busca_binaria.o: busca_binaria.cpp
	g++ busca_binaria.cpp -c
	
clean:
	rm *.o
