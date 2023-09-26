#include <iostream>
using namespace std;

class course
{
    int x, y;

public:
    void Initialize(int xx)
    {
        x = ++xx;
    }

    void Display()
    {
        cout << --x << " ";
    }
};

int main()
{
    course obj;
    obj.Initialize(20);
    obj.Display();
    int* p = (int*)&obj;
    *p = 5;
    obj.Display();
    return 0;
}