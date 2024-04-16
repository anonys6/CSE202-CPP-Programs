#include <iostream>
#include <string>

using namespace std;

void reverseArray(char *arr, int n) {
  for (int i = 0; i < n / 2; i++) {
    char temp = arr[i];
    arr[i] = arr[n - i - 1];
    arr[n - i - 1] = temp;
  }
}

void reverseWords(char *arr, int n) {
  int start = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == ' ') {
      reverseArray(arr + start, i - start);
      start = i + 1;
    }
  }
  reverseArray(arr + start, n - start);
}

int main() {
  int n;
  cin >> n;
  char arr[100];
  cin >> arr;
  reverseWords(arr, n);
  cout << arr << endl;
  return 0;
}