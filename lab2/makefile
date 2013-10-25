date: 
	g++ -std=c++0x -c date.cpp

caesar:
	g++ -std=c++0x -c caesar_date.cpp

gregorian:
	g++ -std=c++0x -c gregorian.cpp

testdate:
	g++ -std=c++0x -c datetest.cpp

test.out: date caesar gregorian
	g++ -std=c++0x -o test.out -I cxxtest tests.cpp date.o caesar_date.o gregorian.o kattistime.cpp

tests.cpp:
	cxxtestgen --error-printer -o tests.cpp test_date.cpp test_gregorian.cpp

test: clean date gregorian tests.cpp test.out
	./test.out

clean:
	$(RM) count *.out *~ *.o tests.cpp
