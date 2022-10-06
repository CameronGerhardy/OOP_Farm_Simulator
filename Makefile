dest = output_files/
sfml = -lsfml-graphics -lsfml-window -lsfml-system

main.cpp: Game.o
	g++ -Wall -std=c++11 main.cpp $(dest)Game.o $(sfml) -o $(dest)main.out

$(dest)Game.o: Game.cpp $(dest)Player.o
	g++ -Wall -std=c++11 $(dest)Player.o Game.cpp -cp

$(dest)Player.o: Player.cpp



run:
	./$(dest)main.out
