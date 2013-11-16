CPP=clang++
CPPFLAGS=-std=c++11 -g

rational: rational.execute
	
rational.clean:
	rm -rf Rational

rational.build: rational.clean
	$(CPP) $(CPPFLAGS) rational/Rational.cpp -o Rational

rational.execute: rational.build
	./Rational

maze: maze.execute
	
maze.clean:
	rm -rf Maze

maze.build: maze.clean
	$(CPP) $(CPPFLAGS) maze/Maze.cpp maze/Map.cpp maze/Render.cpp maze/Structures.cpp -o Maze

maze.execute: maze.build
	./Maze

questions.clean:
	rm -rf tournament/*.class

questions.build: questions.clean
	javac tournament/*.java

question1: questions.build
	java -cp tournament QuestionOne

question2: questions.build
	java -cp tournament QuestionTwo

question3: questions.build
	java -cp tournament QuestionThree

question4: questions.build
	java -cp tournament QuestionFour

question5: questions.build
	java -cp tournament QuestionFive

question6: questions.build
	java -cp tournament QuestionSix