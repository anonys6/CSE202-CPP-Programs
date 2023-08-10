#include <iostream>

using namespace std;

int main()
{
    int a[5] = {14, 4, 5, 2, 13};

    for (int k = 0; k < 4; k++)
    {
        for (int i = 0; i < 5 - k; i++)
        {
            if (a[i] > a[i + 1])
            {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
}