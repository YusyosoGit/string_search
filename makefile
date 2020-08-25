#makefile

search.exe: searchbase.o simple_sch.o main.cpp
	g++ -o search.exe searchbase.o simple_sch.o main.cpp -g
simple_sch.o: simple_sch.h simple_sch.cpp
	g++ -c simple_sch.cpp -g
searchbase.o: searchbase.h searchbase.cpp
	g++ -c searchbase.cpp -g
clean:
	rm -f search.exe *.o
