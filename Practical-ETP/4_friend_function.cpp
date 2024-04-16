#include <iostream>

using namespace std;

class Car {
    int num;

    public:
        void setNum () {
            num = 10;
        }

        friend void car_friend(Car);
};

void car_friend(Car c) {
    cout << c.num;
}

int main() {
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Car g;
    g.setNum();

    car_friend(g);    
    
    return 0;
}