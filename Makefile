CC=g++
flags=-Wall -Werror -Wextra
files=tetris.cpp figures/shapes.cpp figures/shape_template.cpp
target=tetris

all: comp clean

comp:
	clear
	$(CC) $(flags) $(files) -o $(target)
	./$(target)

clean:
	rm -f $(target)