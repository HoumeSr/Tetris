#include <iostream>
#include <vector>
#include "figures/shapes.h"

using namespace std;

vector<vector<int>> create_map(int height, int weight);
void print_map(vector<vector<int>> *map, int size = 2);
void print_char(int _char, int size);