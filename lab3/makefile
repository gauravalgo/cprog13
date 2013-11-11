hello: clean
	g++ -std=c++0x -o curhello.o ncurses-helloworld.cpp character.h character.cpp map.h map.cpp tile.h tile.cpp tree.h tree.cpp object.h object.cpp player.h player.cpp -lncurses
	./curhello.o

clean:
	$(RM) count *.out *~ *.o tests.cpp utdata.txt
