// #include <iostream>
// #include <vector>
// #include <unordered_map>

// using namespace std;

// int main() {
//     int n, credit;
//     string grade;

//     cout << "Enter the total number of courses: ";
//     cin >> n;

//     unordered_map<string, int> course;
//     int credit_sum = 0;

//     for (int i = 0; i < n; i++) {
//         cout << "Enter credit of the course: ";
//         cin >> credit;
//         credit_sum = credit_sum + credit;

//         cout << "Enter grade of the course: ";
//         cin >> grade;

//         course[grade] = credit;
//     }

//     int credit_product = 0;

//     for (auto curr: course) {
//         if (curr.first == "O") {
//             credit_product = credit_product + (curr.second * 10);
//         } else if (curr.first == "A+") {
//             credit_product = credit_product + (curr.second * 9);
//         } else if (curr.first == "A") {
//             credit_product = credit_product + (curr.second * 8);
//         } else if (curr.first == "B+") {
//             credit_product = credit_product + (curr.second * 7);
//         } else if (curr.first == "B") {
//             credit_product = credit_product + (curr.second * 6);
//         } else if (curr.first == "C") {
//             credit_product = credit_product + (curr.second * 5);
//         } else if (curr.first == "D") {
//             credit_product = credit_product + (curr.second * 4);
//         } else if (curr.first == "E") {
//             credit_product = credit_product + (curr.second * 0);
//         }
//     }

//     float cgpa = credit_product / credit_sum;

//     cout << "CGPA: " << cgpa;

//     return 0;

// }


#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, credit;
    string grade;

    cout << "Enter the total number of courses: ";
    cin >> n;

    vector<pair<string, int>> course;
    int credit_sum = 0;

    for (int i = 0; i < n; i++) {
        cout << "Enter credit of the course: ";
        cin >> credit;
        credit_sum = credit_sum + credit;

        cout << "Enter grade of the course: ";
        cin >> grade;

        course.push_back({grade, credit});
    }

    int credit_product = 0;

    for (auto curr: course) {
        if (curr.first == "O") {
            credit_product = credit_product + (curr.second * 10);
        } else if (curr.first == "A+") {
            credit_product = credit_product + (curr.second * 9);
        } else if (curr.first == "A") {
            credit_product = credit_product + (curr.second * 8);
        } else if (curr.first == "B+") {
            credit_product = credit_product + (curr.second * 7);
        } else if (curr.first == "B") {
            credit_product = credit_product + (curr.second * 6);
        } else if (curr.first == "C") {
            credit_product = credit_product + (curr.second * 5);
        } else if (curr.first == "D") {
            credit_product = credit_product + (curr.second * 4);
        } else if (curr.first == "E") {
            credit_product = credit_product + (curr.second * 0);
        }
    }

    float cgpa = (float)credit_product / credit_sum;

    cout << "CGPA: " << cgpa;

    return 0;
}
