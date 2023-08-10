
class Solution
{
public:
    int getKth(int lo, int hi, int k)
    {
        std::vector<std::pair<int, int>> arrPow;

        for (int i = lo; i <= hi; i++)
        {
            int num = i;
            int power = 0;
            while (num != 1)
            {
                if (num % 2 == 0)
                {
                    num = num / 2;
                }
                else
                {
                    num = 3 * num + 1;
                }
                power = power + 1;
            }
            arrPow.push_back(std::make_pair(i, power));
        }

        std::sort(arrPow.begin(), arrPow.end(), [](const std::pair<int, int> &a, const std::pair<int, int> &b)
                  {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second < b.second; });

        return arrPow[k - 1].first;
    }
};

#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {

        for (int j = 0; j < n - i - 1; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n)
{

    for (int i = 1; i < n; i++)
    {

        for (int j = i; j > 0; j--)
        {

            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
            else
            {
                break;
            }
        }
    }
}

int main()
{

    int arr[] = {5, 4, 3, 2, 1};
    insertionSort(arr, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}