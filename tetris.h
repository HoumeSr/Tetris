#include <iostream>
#include <vector>
#include "figures/shapes.h"
#include <memory>
#include <ncurses.h>
#include <unistd.h>
using namespace std;

vector<vector<int>> create_map(int height, int weight);
void print_map(vector<vector<int>> *map, int size = 1);
void print_char(int _char, int size);
int tetris();
void processing_line(vector<vector<int>> *map);
void reg_movement(unique_ptr<Template> *currentFigure, vector<vector<int>> *map);
void create_figure(unique_ptr<Template> *figure, struct coordinates cord);
void init_tetris();
int state_loss(vector<vector<int>> *map);
int random_color();