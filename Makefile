CFLAGS= -g -Wall
SFML_FLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
FAROUT= -lfarout

GTEST_FLAGS= -lgtest_main -lgtest -lpthread

FarOut:
	g++ *.cpp -o FarOut $(SFML_FLAGS) $(CFLAGS)

demo:
	g++ *.cpp -o demo $(SFML_FLAGS) $(FAROUT) $(CFLAGS)

obj:
	g++ -c Library/System.cpp Library/Scene.cpp Library/GameObject.cpp

lib: obj
	ar rcs Library/libfarout.a System.o Scene.o GameObject.o
	rm *.o

install: obj lib
	cp Library/libfarout.a /usr/lib/libfarout.a
	mkdir /usr/include/FarOut
	cp Library/FarOut.h /usr/include/FarOut/
	cp Library/SystemClass.h /usr/include/FarOut/
	cp Library/Scene.h /usr/include/FarOut/
	cp Library/GameObject.h /usr/include/FarOut/
	rm Library/libfarout.a

uninstall:
	rm /usr/lib/libfarout.a
	rm -r /usr/include/FarOut

test:
	g++ *.cpp -o test $(GTEST_FLAGS) $(SFML_FLAGS) $(CFLAGS)

clean:
	rm FarOut test