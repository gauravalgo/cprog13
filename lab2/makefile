date: 
	g++ -std=c++0x -c date.cpp

julian:
	g++ -std=c++0x -c julian.cpp

gregorian:
	g++ -std=c++0x -c gregorian.cpp

test.out: date julian gregorian
	g++ -std=c++0x -o test.out -I cxxtest tests.cpp date.o julian.o gregorian.o

tests.cpp:
	cxxtestgen --error-printer -o tests.cpp test_date.cpp test_julian.cpp test_gregorian.cpp

test: clean tests.cpp test.out
	./test.out

clean:
	$(RM) count *.out *~ *.o tests.cpp
