date: 
	g++ -std=c++0x -c date.cpp

gregorian:
	g++ -std=c++0x -c gregorian.cpp

test.out: date gregorian
	g++ -std=c++0x -o test.out -I /info/cprog12/cxxtest/ tests.cpp date.o gregorian.o kattistime.cpp

tests.cpp:
	/info/cprog12/cxxtest/cxxtestgen.py --error-printer -o tests.cpp test_date.cpp test_gregorian.cpp

test: clean date gregorian tests.cpp test.out
	./test.out

clean:
	$(RM) count *.out *~ *.o tests.cpp
