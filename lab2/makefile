date: clean
	g++ -std=c++0x -c date.cpp

test_date.out:
	g++ -std=c++0x -o test_date.out -I cxxtest tests.cpp date.o

tests.cpp:
	cxxtestgen --error-printer -o tests.cpp test_date.cpp

test: clean date tests.cpp test_date.out
	./test_date.out

clean:
	$(RM) count *.out *~ *.o tests.cpp
