#include <vector>
using namespace std;
struct coordinates
{
    int x, y;
    coordinates(int x, int y);
};

class Template
{
protected:
    int size;
    int **render;
    coordinates pos;

public:
    Template(int size = 0, coordinates coord = coordinates(0, 0));
    virtual void rotate();
    virtual bool check_stop_move(vector<vector<int>> *map);
    virtual void move_down(vector<vector<int>> *map, int speed);
    virtual void move_right(vector<vector<int>> *map);
    virtual void move_left(vector<vector<int>> *map);
    virtual void enter_shape(vector<vector<int>> *map, int type);
    virtual ~Template();
};
