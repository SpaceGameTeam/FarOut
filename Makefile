CFLAGS= -g -Wall
SFML_FLAGS= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

FarOut:
	g++ *.cpp -o FarOut $(SFML_FLAGS) $(CFLAGS)

clean:
	rm FarOut