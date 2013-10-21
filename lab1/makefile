# cleans and compiles a given name.out file 
# $ refers to the given variable
%.out: %.cpp
	g++ -g -std=c++0x -Wall $*.cpp -o $*.out

#borde vara clean också

vector:
	g++ -c -std=c++0x Vector.cpp
#1.2b.cpp kan definieras också så att dne alltid finns
testOld: clean
	#skapa en outfil till must_follow...
	g++ -c must_follow_a.cpp
	# generera testfilen test_must... från 1.2b.cpp 
	cxxtestgen --error-printer -o 1.2b.cpp test_must_follow_a.cpp
	#kompilera testfilen vilken inkluderar biblioteket
	g++ -o test_1.2b.out -I /usr/bin/ 1.2b.cpp must_follow_a.o
	#kör testet
	./test_1.2b.out


#for testing my vector class
test: clean	vector
	cxxtestgen --error-printer -o tv.cpp test_vector.cpp
	g++ -std=c++0x -o test_tv.out -I /usr/bin/ tv.cpp Vector.o
	./test_tv.out

test15: clean vector
	cxxtestgen --error-printer -o tv15.cpp test_template_vector.cpp
	g++ -std=c++0x -o test_tv15.out -I /usr/bin/ tv15.cpp Vector.o
	./test_tv15.out

#make clean, will remove any .out file. 
clean:
	$(RM) count *.out 1.2b.cpp *.o tv.cpp
#	rm *.out
