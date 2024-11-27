struct coordinates
{
    int x, y;
    coordinates(int x, int y);
    //coordinates& operator=(const coordinates coord);
};

class Template
{
protected:
    int size;
    int **render;
    coordinates pos;

public:
    Template(int size = 0, coordinates coord = coordinates(0, 0));
    void rotate();
    ~Template();
};
