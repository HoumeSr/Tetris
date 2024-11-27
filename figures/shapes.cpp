#include "shapes.h"

T_shape::T_shape(coordinates pos) : Template(3, pos)
{
    render[1][1] = 1;
    for (int i = 0; i < 3; i++)
        render[2][i] = 1;
}

I_shape::I_shape(coordinates pos) : Template(4, pos)
{
    for (int i = 0; i < 4; i++)
        render[i][1] = 1;
}

J_shape::J_shape(coordinates pos) : Template(3, pos)
{
    for (int i = 0; i < 3; i++)
        render[i][2] = 1;
    render[2][1] = 1;
}

L_shape::L_shape(coordinates pos) : Template(3, pos)
{
    for (int i = 0; i < 3; i++)
        render[i][0] = 1;
    render[2][1] = 1;
}

O_shape::O_shape(coordinates pos) : Template(2, pos)
{
    for (int i = 0; i < 4; i++)
        render[i / 2][i % 2] = 1;
}

S_shape::S_shape(coordinates pos) : Template(3, pos)
{
    for (int i = 4; i < 8; i++)
        render[i / 3][i % 3] = 1;
}

Z_shape::Z_shape(coordinates pos) : Template(3, pos)
{
    for (int i = 0; i < 2; i++)
        render[1][i] = 1;
    for (int i = 1; i < 3; i++)
        render[2][i] = 1;
}