dest = output_files/
sfml = -lsfml-graphics -lsfml-window -lsfml-system

execute: $(dest)Player.o $(dest)Game.o $(dest)Land.o $(dest)Menu.o $(dest)Button.o #$(dest)Timer.o
	g++ -Wall -std=c++11 main.cpp $(dest)Player.o $(dest)Game.o $(dest)Land.o $(dest)Menu.o $(dest)Button.o $(sfml) -o $(dest)main.out

$(dest)Game.o: Game.cpp
	g++ -Wall -std=c++11 Game.cpp -c
	mv Game.o $(dest)

$(dest)Player.o: Player.cpp
	g++ -Wall -std=c++11 Player.cpp -c
	mv Player.o $(dest)

$(dest)Land.o: Land.cpp
	g++ -Wall -std=c++11 Land.cpp -c
	mv Land.o $(dest)

$(dest)Menu.o: Menu.cpp
	g++ -Wall -std=c++11 Menu.cpp -c
	mv Menu.o $(dest)

$(dest)Button.o: Button.cpp
	g++ -Wall -std=c++11 Button.cpp -c
	mv Button.o $(dest)

# $(dest)Timer.o: Timer.cpp
# 	g++ -Wall -std=c++11 Timer.cpp -c
# 	mv Timer.o $(dest)

run:
	./$(dest)main.out

test:
	g++ menutest.cpp Menu.cpp Button.cpp $(sfml) -o $(dest)menutest.out
	./$(dest)menutest.out 
