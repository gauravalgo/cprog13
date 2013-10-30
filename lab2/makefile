date: 
	g++ -std=c++0x -c date.cpp

julian:
	g++ -std=c++0x -c julian.cpp

gregorian:
	g++ -std=c++0x -c gregorian.cpp

testdate:
	g++ -std=c++0x -c datetest.cpp

test.out: date gregorian julian
	g++ -std=c++0x -o test.out -I cxxtest tests.cpp date.o gregorian.o kattistime.cpp julian.o

tests.cpp:
	cxxtestgen --error-printer -o tests.cpp test_date.cpp test_gregorian.cpp test_julian.cpp

test: clean date gregorian julian tests.cpp test.out
	./test.out

clean:
	$(RM) count *.out *~ *.o tests.cpp
