#include "shape_template.h"
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
Template::~Template()
{
    for (int i = 0; i < size; i++)
    {
        delete[] render[i];
    }
    delete[] render;
}