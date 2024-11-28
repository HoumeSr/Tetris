#include <iostream>
#include <vector>
#include "figures/shapes.h"
#include <memory>

using namespace std;

vector<vector<int>> create_map(int height, int weight);
void print_map(vector<vector<int>> *map, int size = 1);
void print_char(int _char, int size);
void tetris();
void processing_line(vector<vector<int>> *map);