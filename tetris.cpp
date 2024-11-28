#include "tetris.h"
using namespace std;
vector<vector<int>> create_map(int height, int weight)
{
    vector<vector<int>> map(height, vector<int>(weight));
    for (int i = 0; i < height; i++)
        for (int j = 0; j < weight; j++)
            map[i][j] = 0;
    return map;
}
void print_map(vector<vector<int>> *map, int size)
{
    if (map == nullptr || (*map).size() == 0)
        return;
    int height = (*map).size(), weight = (*map)[0].size();

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < size; j++)
        {
            print_char(-1, size);
            for (int k = 0; k < weight; k++)
            {
                print_char((*map)[i][k], size);
            }
            print_char(-1, size);
            cout << endl;
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < weight + 2; j++)
            print_char(-1, size);
        cout << endl;
    }
    cout << endl;
}

void print_char(int _char, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (_char == -1)
            cout << '#';
        else if (_char == 0)
            cout << '0';
        else if (_char == 1)
            cout << '*';
    }
}

void processing_line(vector<vector<int>> *map)
{
    if (map == nullptr || (*map).size() == 0)
        return;
    int height = (*map).size(), weight = (*map)[0].size();
    for (int i = 0; i < height; i++)
    {
        bool clearing = true;
        for (int j = 0; j < weight && clearing; j++)
            if ((*map)[i][j] == 0)
                clearing = false;
        for (int j = i; j > 0 && clearing; j--)
        {
            for (int k = 0; k < weight; k++)
            {
                // cout << j << ' ' << k << endl;
                (*map)[j][k] = (*map)[j - 1][k];
            }
        }
        for (int j = 0; j < weight && clearing; j++)
            (*map)[0][j] = 0;
    }
}
void create_figure(unique_ptr<Template> *figure, struct coordinates cord)
{
    int type = rand() % 7;
    cout << type << endl;
    if (type == 0)
        *figure = unique_ptr<Template>(new T_shape(cord));
    else if (type == 1)
        *figure = unique_ptr<Template>(new I_shape(cord));
    else if (type == 2)
        *figure = unique_ptr<Template>(new S_shape(cord));
    else if (type == 3)
        *figure = unique_ptr<Template>(new J_shape(cord));
    else if (type == 4)
        *figure = unique_ptr<Template>(new L_shape(cord));
    else if (type == 5)
        *figure = unique_ptr<Template>(new O_shape(cord));
    else if (type == 6)
        *figure = unique_ptr<Template>(new Z_shape(cord));
}

void tetris()
{
    srand(time(0));
    vector<vector<int>> map = create_map(20, 10);
    int size = 2;
    unique_ptr<Template> currentFigure;
    struct coordinates cord = {0, 0};
    create_figure(&currentFigure, cord);
    char ch;
    currentFigure->enter_shape(&map, 1);
    print_map(&map, size);
    while (cin >> ch)
    {
        currentFigure->enter_shape(&map, 0);
        if (ch == 'd')
        {
            currentFigure->move_right(&map);
        }
        else if (ch == 'a')
        {
            currentFigure->move_left(&map);
        }
        else if (ch == 's')
        {
            currentFigure->move_down(&map, 1);
        }
        else if (ch == 'w')
        {
            currentFigure->rotate();
        }
        if (currentFigure->check_stop_move(&map))
        {
            currentFigure->enter_shape(&map, 1);
            processing_line(&map);
            create_figure(&currentFigure, {0, 0});
        }
        currentFigure->enter_shape(&map, 1);
        print_map(&map, size);
    }
}
int main()
{
    tetris();
}