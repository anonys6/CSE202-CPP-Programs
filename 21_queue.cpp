#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    int countStudents(vector<int> &students, vector<int> &sandwiches) {
        queue<int> stu;
        for (int student : students) {
            stu.push(student);
        }
        int i = 0;
        int count = students.size();
        while (!stu.empty()) {
            if (stu.front() == sandwiches[i]) {
                stu.pop();
                i++;
                count--;
            } else {
                int cnt = 0;
                while (cnt < count && stu.front() != sandwiches[i]) {
                    int temp = stu.front();
                    stu.pop();
                    stu.push(temp);
                    cnt++;
                }
                if (cnt == count)
                    break;
            }
        }
        return count;
    }
};

int main() {
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};
    Solution s;
    int result = s.countStudents(students, sandwiches);
    cout << "Remaining students: " << result << endl;
    return 0;
}