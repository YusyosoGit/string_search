#makefile

search.exe: searchbase.o simple_sch.o BM_sch.o main.cpp
	g++ -o search.exe searchbase.o BM_sch.o simple_sch.o main.cpp -g
#BM_sch.exe: searchbase.o BM_sch.o main.cpp
#	g++ -o BM_sch.exe searchbase.o BM_sch.o main.cpp -g

BM_sch.o: BM_sch.h BM_sch.cpp
	g++ -c BM_sch.cpp -g
simple_sch.o: simple_sch.h simple_sch.cpp
	g++ -c simple_sch.cpp -g
searchbase.o: searchbase.h searchbase.cpp
	g++ -c searchbase.cpp -g
clean:
	rm -f *.exe *.o
