CFLAGS= -g -Wall
SFML_FLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
FAROUT= -lfarout
GTEST_FLAGS= -lgtest_main -lgtest -lpthread

demo-local:
	g++ *.cpp FarOut/*.cpp -o demo $(SFML_FLAGS) $(CFLAGS)

demo:
	g++ *.cpp -o demo $(SFML_FLAGS) $(FAROUT) $(CFLAGS)

obj:
	g++ -c FarOut/System.cpp FarOut/Scene.cpp FarOut/GameObject.cpp

lib: obj
	ar rcs FarOut/libfarout.a System.o Scene.o GameObject.o
	rm *.o

install: obj lib
	cp FarOut/libfarout.a /usr/lib/libfarout.a
	mkdir /usr/include/FarOut
	cp FarOut/FarOut.h /usr/include/FarOut/
	cp FarOut/SystemClass.h /usr/include/FarOut
	cp FarOut/Scene.h /usr/include/FarOut/
	cp FarOut/GameObject.h /usr/include/FarOut/
	rm FarOut/libfarout.a

uninstall:
	rm /usr/lib/libfarout.a
	rm -r /usr/include/FarOut

systemtest:
	g++ FarOut/*.cpp -o systemtest $(GTEST_FLAGS) $(SFML_FLAGS) $(CFLAGS)

runtest: clean systemtest
	./systemtest

clean:
	rm -f demo *.o systemtest *.a