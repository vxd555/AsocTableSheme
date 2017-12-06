a: testmap.o
	g++ -std=c++11 -g -Wall -pedantic $^ -o $@

testmap.o: testmap.cpp employee.h map_template.h
	g++ -std=c++11 -g -c -Wall -pedantic $< -o $@
	
.PHONY: clean

clean:
	-rm a testmap.o
