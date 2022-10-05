dest = output_files/
sfml = -lsfml-graphics -lsfml-window -lsfml-system

compile: main.cpp
	g++ -Wall -std=c++11 main.cpp Game.cpp Player.cpp $(sfml) -o $(dest)main.out


run:
	./$(dest)main.out
