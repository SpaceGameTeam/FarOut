CFLAGS= -g -Wall
SFML_FLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
GTEST_FLAGS= -lgtest_main -lgtest -lpthread

FarOut:
	g++ *.cpp -o FarOut $(SFML_FLAGS) $(CFLAGS)

FarOut-lib:
	g++ main.cpp PrototypeScene.cpp PlanetarySystem.cpp Asteroid.cpp Ship.cpp AlienShip.cpp PrototypeMenu.cpp farout.a -o FarOut $(SFML_FLAGS) $(CFLAGS)

test:
	g++ *.cpp -o test $(GTEST_FLAGS) $(SFML_FLAGS) $(CFLAGS)

clean:
	rm FarOut test