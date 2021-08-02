CFLAGS= -g -Wall
SFML_FLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
GTEST_FLAGS= -lgtest_main -lgtest -lpthread

FarOut:
	g++ *.cpp -o FarOut $(SFML_FLAGS) $(CFLAGS)

SystemTest:
	g++ System.cpp SystemTest.cpp -o SystemTest $(GTEST_FLAGS) $(SFML_FLAGS) $(CFLAGS)

clean:
	rm FarOut SystemTest