dest = output_files/
sfml = -lsfml-graphics -lsfml-window -lsfml-system

execute: $(dest)Player.o $(dest)Game.o $(dest)Land.o $(dest)Menu.o $(dest)Button.o $(dest)Farmland.o $(dest)Grassland.o $(dest)WheatCrop.o $(dest)Bean.o $(dest)CornCrop.o $(dest)Timer.o 
	g++ -Wall -std=c++11 main.cpp $(dest)Player.o $(dest)Game.o $(dest)Land.o $(dest)Menu.o $(dest)Button.o $(dest)Farmland.o $(dest)Grassland.o $(dest)WheatCrop.o $(dest)Bean.o  $(dest)CornCrop.o $(dest)Timer.o $(sfml) -o $(dest)main.out

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

$(dest)Farmland.o: Farmland.cpp
	g++ -Wall -std=c++11 Farmland.cpp -c
	mv Farmland.o $(dest)

$(dest)Grassland.o: Grassland.cpp
	g++ -Wall -std=c++11 Grassland.cpp -c
	mv Grassland.o $(dest)

$(dest)WheatCrop.o: WheatCrop.cpp
	g++ -Wall -std=c++11 WheatCrop.cpp -c
	mv WheatCrop.o $(dest)

$(dest)Bean.o: Bean.cpp
	g++ -Wall -std=c++11 Bean.cpp -c
	mv Bean.o $(dest)

$(dest)CornCrop.o: CornCrop.cpp
	g++ -Wall -std=c++11 CornCrop.cpp -c
	mv CornCrop.o $(dest)

$(dest)Timer.o: Timer.cpp
	g++ -Wall -std=c++11 Timer.cpp -c
	mv Timer.o $(dest)

run:
	./$(dest)main.out

test:
	g++ menutest.cpp Menu.cpp Button.cpp $(sfml) -o $(dest)menutest.out
	./$(dest)menutest.out 
