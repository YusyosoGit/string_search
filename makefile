#makefile

search.exe: searchbase.h simple_sch.h main.cpp
	g++ -o search.exe main.cpp -g
#search.o: searchbase.h simple_sch.cpp
#	g++ -c simple_sch.cpp -g
clean:
	rm -f search.exe search.o
