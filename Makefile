CPP=clang++
CPPFLAGS=-std=c++11 -stdlib=libstdc++ -Weverything -g

rational: rational.execute
	
rational.clean:
	rm -rf rational

rational.build: rational.clean
	$(CPP) $(CPPFLAGS) rational.cpp -o rational

rational.execute: rational.build
	./rational
