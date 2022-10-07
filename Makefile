dest = output_files/
sfml = -lsfml-graphics -lsfml-window -lsfml-system

execute: $(dest)Player.o $(dest)Game.o $(dest)Land.o
	g++ -Wall -std=c++11 main.cpp $(dest)Player.o $(dest)Game.o $(dest)Land.o $(sfml) -o $(dest)main.out

$(dest)Game.o: Game.cpp
	g++ -Wall -std=c++11 Game.cpp -c
	mv Game.o $(dest)

$(dest)Player.o: Player.cpp
	g++ -Wall -std=c++11 Player.cpp -c
	mv Player.o $(dest)

$(dest)Land.o: Land.cpp
	g++ -Wall -std=c++11 Land.cpp -c
	mv Land.o $(dest)



run:
	./$(dest)main.out
