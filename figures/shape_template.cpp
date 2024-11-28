#include "shape_template.h"
#include <vector>
#include <iostream>
using namespace std;
coordinates::coordinates(int x = 0, int y = 0)
{
    this->x = x;
    this->y = y;
}

Template::Template(int size, coordinates pos)
{
    this->size = size;
    render = new int *[size];
    for (int i = 0; i < size; i++)
        render[i] = new int[size];
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            render[i][j] = 0;
    this->pos = pos;
}

void Template::rotate()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            int x = render[i][j];
            render[i][j] = render[j][i];
            render[j][i] = x;
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size / 2; j++)
        {
            int x = render[i][j];
            render[i][j] = render[i][size - j - 1];
            render[i][size - j - 1] = x;
        }
    }
}
bool Template::check_stop_move(vector<vector<int>> *map)
{
    if (map == nullptr || (*map).size() == 0)
        return false;
    int height = (int)(*map).size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (render[i][j] == 0)
                continue;
            if (pos.y + i + 1 == height)
                return true;
            if ((*map)[pos.y + i + 1][pos.x + j] == 1)
                return true;
        }
    }
    return false;
}

void Template::move_down(vector<vector<int>> *map, int speed)
{
    if (check_stop_move(map) == 0)
    {
        pos.y += speed;
    }
}
void Template::move_left(vector<vector<int>> *map)
{
    if (map == nullptr || (*map).size() == 0)
        return;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (render[i][j] == 0)
                continue;
            if (pos.x + j == 0)
                return;
            if ((*map)[i][pos.x + j - 1] == 1)
                return;
        }
    }
    pos.x -= 1;
}
void Template::move_right(vector<vector<int>> *map)
{
    if (map == nullptr || (*map).size() == 0)
        return;
    int weight = (int)(*map)[0].size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (render[i][j] == 0)
                continue;
            if (pos.x + j + 1 == weight)
                return;
            if ((*map)[i][pos.x + j + 1] == 1)
                return;
        }
    }
    pos.x += 1;
}
void Template::enter_shape(vector<vector<int>> *map, int type)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (render[i][j] == 0)
                continue;
            (*map)[pos.y + i][pos.x + j] = type;
        }
    }
}
Template::~Template()
{
    for (int i = 0; i < size; i++)
    {
        delete[] render[i];
    }
    delete[] render;
}