#include <iostream>

using namespace std;

int main()
{
    string text = "hello world";

    char ans[12];

    for (int i = 0; i < text.length(); i++) {
        if (text[i] == ' ') {
            ans[i] = ' ';
            continue;
        }
        char ch = 'a';
        if (ans == text) {
            break;
        }
        for (int j = 0; j < 26; j++) {
            ans[i] = ch;
            if (ans[i] == text[i]) {
                cout << ans << endl;
                break;
            } else {
                cout << ans << endl;
            }
            ch++;
        }
    }

    cout << ans << endl;
    
    return 0;
}