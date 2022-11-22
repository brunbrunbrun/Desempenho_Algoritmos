main: main.o busca_sequencial.o busca_binaria.o
	g++ main.o busca_sequencial.o busca_binaria.o -static-libgcc -static-libstdc++ -o main.exe

main.o: main.cpp header.h
	g++ main.cpp -static-libgcc -static-libstdc++ -c

busca_sequencial.o: busca_sequencial.cpp
	g++ busca_sequencial.cpp -static-libgcc -static-libstdc++ -c

busca_binaria.o: busca_binaria.cpp
	g++ busca_binaria.cpp -static-libgcc -static-libstdc++ -c

clean:
	rm *.o
