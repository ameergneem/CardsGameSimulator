
all: reviiot
run: reviiot
reviiot:bin/reviiot.o bin/Game.o bin/Deck.o bin/Card.o bin/NumericCard.o bin/FigureCard.o bin/Hand.o bin/Player.o
	g++ -o bin/reviiot  bin/reviiot.o bin/Game.o bin/Deck.o bin/Card.o bin/NumericCard.o bin/FigureCard.o bin/Hand.o bin/Player.o


bin/Deck.o:src/Deck.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Deck.o src/Deck.cpp

bin/Card.o:src/Card.cpp
		g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Card.o src/Card.cpp

bin/NumericCard.o:src/NumericCard.cpp
			g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/NumericCard.o src/NumericCard.cpp
bin/FigureCard.o:src/FigureCard.cpp
			g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/FigureCard.o src/FigureCard.cpp

bin/Hand.o:src/Hand.cpp
			g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Hand.o src/Hand.cpp

bin/Player.o:src/Player.cpp
			g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Player.o src/Player.cpp

bin/Game.o:src/Game.cpp
			g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Game.o src/Game.cpp

bin/reviiot.o:src/reviiyot.cpp
			g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/reviiot.o src/reviiyot.cpp


clean:
	rm -f bin/*
