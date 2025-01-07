#include "shape_template.h"
#include <vector>
#include <iostream>
using namespace std;
coordinates::coordinates(double x = 0, double y = 0)
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
            if ((int)pos.y + i + 1 == height)
                return true;
            if ((*map)[(int)pos.y + i + 1][(int)pos.x + j] > 0)
                return true;
        }
    }
    return false;
}
bool Template::check_position(vector<vector<int>> *map)
{
    int width = (*map)[0].size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (render[i][j] > 0)
            {
                if ((int)pos.x + j >= width || (int)pos.x + j < 0)
                    return 1;
                if ((*map)[(int)pos.y + i][(int)pos.x + j] > 0)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
void Template::move_down(vector<vector<int>> *map, double speed)
{
    if (check_stop_move(map) == 0)
    {
        pos.y += speed;
    }
}
int Template::move_left(vector<vector<int>> *map)
{
    if (map == nullptr || (*map).size() == 0)
        return 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (render[i][j] == 0)
                continue;
            if ((int)pos.x + j == 0)
                return 0;
            if ((*map)[i][(int)pos.x + j - 1] > 0)
                return 0;
        }
    }
    pos.x -= 1;
    return 1;
}
int Template::move_right(vector<vector<int>> *map)
{
    if (map == nullptr || (*map).size() == 0)
        return 0;
    int weight = (int)(*map)[0].size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (render[i][j] == 0)
                continue;
            if ((int)pos.x + j + 1 == weight)
                return 0;
            if ((*map)[i][(int)pos.x + j + 1] > 0)
                return 0;
        }
    }
    pos.x += 1;
    return 1;
}
int Template::enter_shape(vector<vector<int>> *map, int type)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (render[i][j] == 0)
                continue;
            if (type > 0 && (*map)[(int)pos.y + i][(int)pos.x + j] > 0)
                return 1;
            (*map)[(int)pos.y + i][(int)pos.x + j] = type;
        }
    }
    return 0;
}
Template::~Template()
{
    for (int i = 0; i < size; i++)
    {
        delete[] render[i];
    }
    delete[] render;
}