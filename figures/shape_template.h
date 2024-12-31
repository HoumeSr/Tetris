#include <vector>
using namespace std;
struct coordinates
{
    double x, y;
    coordinates(double x, double y);
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
    virtual void move_down(vector<vector<int>> *map, double speed);
    virtual int move_right(vector<vector<int>> *map);
    virtual int move_left(vector<vector<int>> *map);
    virtual bool check_position(vector<vector<int>> *map);
    virtual int enter_shape(vector<vector<int>> *map, int type);
    virtual ~Template();
};
