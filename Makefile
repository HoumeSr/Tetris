CC=g++
flags=-Wall -Werror -Wextra
files=tetris.cpp figures/shapes.cpp figures/shape_template.cpp
target=tetris

all:
	clear
	$(CC) $(flags) $(files) -o $(target)
	./$(target)


$(TARGET):
	$(CC) $(flags) $(files) -o $(target)