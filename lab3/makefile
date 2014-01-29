hello: clean gui map icemap treemap maphandler
	g++ -std=c++11 -o curhello.o ncurses-helloworld.cpp character.h character.cpp map.o maphandler.o icemap.o treemap.o tile.h tile.cpp icetile.h icetile.cpp treetile.h treetile.cpp object.h object.cpp player.h player.cpp rocktile.h rocktile.cpp food.h food.cpp inventorable.h inventorable.cpp grass_tile.h grass_tile.cpp button.h button.cpp teleporter.cpp teleporter.h gui.o terry.h terry.cpp -lncurses

run: hello
	./curhello.o

gui:
	g++ -std=c++11 -c gui.cpp gui.h -lncurses

map:
	g++ -std=c++11 -c map.cpp map.h -lncurses

icemap:
	g++ -std=c++11 -c icemap.cpp icemap.h -lncurses

treemap:
	g++ -std=c++11 -c treemap.cpp treemap.h -lncurses

maphandler:
	g++ -std=c++11 -c maphandler.cpp maphandler.h -lncurses

mem: hello
	valgrind --tool=memcheck --leak-check=yes ./curhello.o

clean:
	$(RM) count *.out *~ *.o *.h.gch tests.cpp utdata.txt
