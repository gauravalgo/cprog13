date: 
	g++ -std=c++0x -c date.cpp

julian:
	g++ -std=c++0x -c julian.cpp

gregorian:
	g++ -std=c++0x -c gregorian.cpp

calendar:
	g++ -std=c++0x -c calendar.cpp

datetest:
	g++ date.h date.cpp gregorian.h gregorian.cpp julian.h julian.cpp kattistime.h kattistime.cpp datetest.cpp
	./a.out

test.out: tests.cpp date gregorian julian calendar
	g++ -std=c++0x -o test.out -I cxxtest tests.cpp date.o gregorian.o kattistime.cpp julian.o calendar.o

tests.cpp:
	cxxtestgen --error-printer -o tests.cpp test_date.cpp test_gregorian.cpp test_julian.cpp test_calendar.cpp

test: clean test.out
	./test.out

clean:
	$(RM) count *.out *~ *.o tests.cpp
