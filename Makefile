CPP=clang++
CPPFLAGS=-std=c++11 -stdlib=libstdc++ -g

rational: rational.execute
	
rational.clean:
	rm -rf Rational

rational.build: rational.clean
	$(CPP) $(CPPFLAGS) Rational.cpp -o Rational

rational.execute: rational.build
	./Rational

maze: maze.execute
	
maze.clean:
	rm -rf Maze

maze.build: maze.clean
	$(CPP) $(CPPFLAGS) Maze.cpp Map.cpp Render.cpp Structures.cpp -o Maze

maze.execute: maze.build
	./Maze
