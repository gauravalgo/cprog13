date: 
	g++ -std=c++0x -c date.cpp

middle:
	g++ -std=c++0x -c middle.cpp

julian:
	g++ -std=c++0x -c julian.cpp

gregorian:
	g++ -std=c++0x -c gregorian.cpp

calendar:
	g++ -std=c++0x -c calendar.cpp

datetest:
	g++ date.h date.cpp gregorian.h gregorian.cpp julian.h julian.cpp kattistime.h kattistime.cpp datetest.cpp
	./a.out

test.out: tests.cpp date middle gregorian julian calendar
	g++ -std=c++0x -o test.out -I cxxtest tests.cpp date.o middle.o gregorian.o kattistime.cpp julian.o calendar.o

csc_test.out: tests.cpp date middle gregorian julian calendar
	g++ -std=c++0x -o test.out -I /info/DD2387/kurskatalog/cxxtest/ tests.cpp date.o middle.o gregorian.o kattistime.cpp julian.o calendar.o

tests.cpp:
	cxxtestgen --error-printer -o tests.cpp test_date.cpp test_gregorian.cpp test_julian.cpp test_calendar.cpp

csc_tests.cpp:
	/info/DD2387/kurskatalog/cxxtest/cxxtestgen.py --error-printer -o tests.cpp test_date.cpp test_gregorian.cpp test_julian.cpp test_calendar.cpp

test: clean test.out
	./test.out

compile_cal_test:
	g++ -std=c++0x -o cal_test.o calendar.cpp cprog09lab23.cpp kattistime.h kattistime.cpp gregorian.h gregorian.cpp julian.h julian.cpp date.h date.cpp middle.h middle.cpp
	cat kurskatalogen/lab23.in |	./cal_test.o > utdata.txt
	cat utdata.txt
cal_test: clean compile_cal_test
	diff utdata.txt kurskatalogen/lab23.out

clean:
	$(RM) count *.out *~ *.o tests.cpp utdata.txt
