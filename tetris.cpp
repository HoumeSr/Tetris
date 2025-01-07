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
            printw("\n");
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < weight + 2; j++)
            print_char(-1, size);
        printw("\n");
    }
    printw("\n");
    refresh();
}

void print_char(int _char, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (_char == -1)
        {
            attron(COLOR_PAIR(1));
            printw(" #");
            attroff(COLOR_PAIR(1));
        }
        else if (_char == 0)
            printw("  ");
        else
        {
            attron(COLOR_PAIR(_char));
            printw(" *");
            attroff(COLOR_PAIR(_char));
        }
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
                (*map)[j][k] = (*map)[j - 1][k];
            }
        }
        for (int j = 0; j < weight && clearing; j++)
            (*map)[0][j] = 0;
    }
}
void reg_movement(unique_ptr<Template> *currentFigure, vector<vector<int>> *map)
{
    int ch = getch();
    double speed = 0.2;
    if (ch == 'd')
    {
        (*currentFigure)->move_right(map);
        if ((*currentFigure)->check_position(map))
            (*currentFigure)->move_left(map);
    }
    else if (ch == 'a')
    {
        (*currentFigure)->move_left(map);
        if ((*currentFigure)->check_position(map))
            (*currentFigure)->move_right(map);
    }
    else if (ch == 'w')
    {
        (*currentFigure)->rotate();
        if ((*currentFigure)->check_position(map))
            for (int i = 0; i < 3; ++i)
                (*currentFigure)->rotate();
    }
    else if (ch == 's')
    {
        while (not(*currentFigure)->check_stop_move(map))
            (*currentFigure)->move_down(map, speed);
    }
    (*currentFigure)->move_down(map, speed);
}
void create_figure(unique_ptr<Template> *figure, struct coordinates cord)
{
    int type = rand() % 7;
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
void init_tetris()
{
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    srand(time(0));
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_WHITE, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
}
int random_color()
{
    return rand() % 6 + 2;
}
unique_ptr<Template> init_figure(vector<vector<int>> *map, int color)
{
    unique_ptr<Template> currentFigure;
    struct coordinates cord = {5, 0};
    create_figure(&currentFigure, cord);
    currentFigure->enter_shape(map, color);
    return currentFigure;
}
int state_loss(vector<vector<int>> *map)
{
    int width = (*map)[0].size();
    for (int i = 0; i < width; ++i)
        if ((*map)[0][i])
            return 1;
    return 0;
}
int tetris()
{
    init_tetris();
    vector<vector<int>> map = create_map(20, 10);
    int size = 2;
    int color = random_color();
    unique_ptr<Template> currentFigure = init_figure(&map, color);
    print_map(&map, size);
    int loss = 0;
    while (loss == 0)
    {
        currentFigure->enter_shape(&map, 0);
        reg_movement(&currentFigure, &map);
        if (currentFigure->check_stop_move(&map))
        {
            loss = currentFigure->enter_shape(&map, color);
            processing_line(&map);
            create_figure(&currentFigure, {5, 0});
            color = random_color();
        }
        clear();
        loss = currentFigure->enter_shape(&map, color);
        print_map(&map, size);
        usleep(80000);
    }
    endwin();
    return 0;
}
int main()
{
    tetris();
}