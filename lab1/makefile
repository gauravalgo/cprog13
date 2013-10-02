%.out:	%.cpp
	g++ -g -std=c++0x -Wall $*.cpp -o $*.out

1.2b.cpp:
	cxxtestgen --error-printer -o 1.2b.cpp test_must_follow_a.cpp

must_follow_a.o:
	g++ -c must_follow_a.cpp

test_must_follow_a.out:
	g++ -o test_1.2b.out -I cxxtest 1.2b.cpp must_follow_a.o

test: clean must_follow_a.o 1.2b.cpp test_must_follow_a.out 
	./test_1.2b.out

clean: 
	$(RM) count *.out *~ *.o 1.2b.cpp
