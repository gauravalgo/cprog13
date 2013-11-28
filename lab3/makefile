hello: clean
	g++ -std=c++11 -o curhello.o ncurses-helloworld.cpp character.h character.cpp map.h map.cpp tile.h tile.cpp treetile.h treetile.cpp object.h object.cpp player.h player.cpp rocktile.h rocktile.cpp food.h food.cpp inventorable.h inventorable.cpp grass_tile.h grass_tile.cpp button.h button.cpp actor.h actor.cpp -lncurses

run: hello
	./curhello.o

mem: hello
	valgrind --tool=memcheck --leak-check=yes ./curhello.o

clean:
	$(RM) count *.out *~ *.o tests.cpp utdata.txt
