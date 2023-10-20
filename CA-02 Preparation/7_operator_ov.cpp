#include <iostream>

using namespace std;

class Complex {
private:
    int a, b;

public:
    inline void setData(int, int);
    inline void getData();
    friend Complex operator-(Complex);
};

void Complex::setData(int x, int y)
{
    a = x;
    b = y;
}

void Complex::getData()
{
    cout << a << " + " << b << "i" << endl;
}

Complex operator-(Complex c)
{
    Complex temp;
    temp.a = -c.a;
    temp.b = -c.b;
    return temp;
}

int main()
{
    Complex c1, c2;
    c1.setData(3, 4); // 3 + 4i
    c1.getData();
    c2 = -c1;
    c2.getData();
    return 0;
}



// Adding two complex number using +operator overloading

// #include <iostream>
// using namespace std;
// class Complex
// {
//     private:
//         int a, b;
//         string s;
//     public:
//         inline void setData(int, int);
//         inline void getData();
//         // friend Complex operator+(Complex, Complex);
// };

// void Complex::setData(int x, int y)
// {
//     a = x;
//     b = y;
// }
// void Complex::getData()
// {
//     cout<<a<<" + "<<b<<"i"<<endl;
// }

// Complex operator+ (Complex x, Complex y)
// {
//     Complex temp;
//     temp.a = x.a + y.a;
//     temp.b = x.b + y.b;
//     return temp;
// }

// int main()
// {
//     Complex m, n, o;

//     m.setData(3, 4);
//     n.setData(5, 6);

//     m.getData();
//     n.getData();

//     o = m + n; // o = operator+(m, n);
//     // o = operator+ (m, n);

//     o.getData();

//     return 0;
// }