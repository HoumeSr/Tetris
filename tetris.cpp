#include "tetris.h"

void tetris()
{
    vector<vector<int>> map = create_map(20, 10);
    print_map(&map);
}

vector<vector<int>> create_map(int height, int weight)
{
    vector<vector<int>> map(height, vector<int>(weight));
    for (int i = 0; i < height; i++)
        for (int j = 0; j < weight; j++)
            map[i][j] = 0;
    return map;
}
void print_map(vector<vector<int>> *map, int size = 2)
{
    for (int i = 0; i < (*map).size(); i++)
    {
        for (int j = 0; j < (*map)[i].size(); j++)
        {
            for (int k = 0; k < size; k++)
            {
                print_char((*map)[i][j], size);
            }
        }
        cout << endl;
    }
}

void print_char(int _char, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (_char == -1)
            cout << '#';
        else if (_char == 0)
            cout << ' ';
        else if (_char == 1)
            cout << '*';
    }
}