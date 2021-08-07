CFLAGS= -g -Wall
SFML_FLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
GTEST_FLAGS= -lgtest_main -lgtest -lpthread

FarOut:
	g++ *.cpp -o FarOut $(SFML_FLAGS) $(CFLAGS)

demo:
	g++ main.cpp PrototypeScene.cpp PlanetarySystem.cpp Asteroid.cpp Ship.cpp AlienShip.cpp PrototypeMenu.cpp farout.a -o FarOut-demo $(SFML_FLAGS) $(CFLAGS)

obj:
	g++ -c System.cpp Scene.cpp GameObject.cpp

lib: obj
	ar rcs libfarout.a System.o Scene.o GameObject.o

install: obj lib
	cp libfarout.a /usr/lib/libfarout.a
	mkdir /usr/include/FarOut
	cp FarOut.h /usr/include/FarOut/
	cp SystemClass.h /usr/include/FarOut/
	cp Scene.h /usr/include/FarOut/
	cp GameObject.h /usr/include/FarOut/

uninstall:
	rm /usr/lib/libfarout.a
	rm -r /usr/include/FarOut

test:
	g++ *.cpp -o test $(GTEST_FLAGS) $(SFML_FLAGS) $(CFLAGS)

clean:
	rm FarOut test
	rm libfarout.a