vector:
	g++ -std=c++0x -c vector.cpp

test_vector.out:
	g++ -std=c++0x -o test_vector.out -I cxxtest tests.cpp vector.o

test: clean vector tests.cpp test_vector.out
	./test_vector.out

tests.cpp:
	cxxtestgen --error-printer -o tests.cpp test_vector.cpp

kattis: clean
	cat vector.h > kth_cprog_vektor.cpp
	cat vector.cpp >> kth_cprog_vektor.cpp
	g++ -std=c++11 -c kth_cprog_vektor.cpp

test2: clean vector
	g++ -g -std=c++0x -Wall test_template_vec.cpp vector.o -o test_template_vec.out
	./test_template_vec.out

clean:
	$(RM) count *.out *~ *.o tests.cpp
