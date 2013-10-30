date: 
	g++ -std=c++0x -c date.cpp

julian:
	g++ -std=c++0x -c julian.cpp

gregorian:
	g++ -std=c++0x -c gregorian.cpp

datetest:
	g++ date.h date.cpp gregorian.h gregorian.cpp julian.h julian.cpp kattistime.h kattistime.cpp datetest.cpp

testdate: date gregorian julian
	g++ -std=c++0x -c datetest.cpp
	./datetest.o

test.out: date gregorian julian
	g++ -std=c++0x -o test.out -I cxxtest tests.cpp date.o gregorian.o kattistime.cpp julian.o

tests.cpp:
	cxxtestgen --error-printer -o tests.cpp test_date.cpp test_gregorian.cpp test_julian.cpp

test: clean date gregorian julian tests.cpp test.out
	./test.out

clean:
	$(RM) count *.out *~ *.o tests.cpp
