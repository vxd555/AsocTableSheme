a: testmap.o
	g++ -std=c++11 -g -Wall -pedantic $^ -o $@

testmap.o: testmap.cpp map_template.h employee.h
	g++ -std=c++11 -g -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm a testmap.o employee.o map_template.o
