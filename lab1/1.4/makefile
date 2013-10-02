vector:
	g++ -std=c++11 -c vector.cpp

test_vector.out:
	g++ -std=c++11 -o test_vector.out -I cxxtest tests.cpp vector.o

test: clean vector tests.cpp test_vector.out
	./test_vector.out

tests.cpp:
	cxxtestgen --error-printer -o tests.cpp test_vector.cpp

clean:
	$(RM) count *.out *~ *.o tests.cpp
