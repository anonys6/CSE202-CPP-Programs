#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int calPoints(vector<string> &operations) {
        stack<int> score;

        for (int i = 0; i < operations.size(); i++) {
            if (isdigit(operations[i][0]) || operations[i][0] == '-') {
                score.push(stoi(operations[i]));
            } else if (operations[i] == "C") {
                score.pop();
            } else if (operations[i] == "D") {
                score.push(score.top() * 2);
            } else if (operations[i] == "+") {
                int num1, sum;
                num1 = score.top();
                score.pop();
                sum = num1 + score.top();
                score.push(num1);
                score.push(sum);
            }
        }

        int sum = 0;
        while (!score.empty()) {
            sum += score.top();
            score.pop();
        }

        return sum;
    }
};

int main() {
    // Test the calPoints function
    Solution solution;
    vector<string> operations = {"5", "2", "C", "D", "+"};
    int result = solution.calPoints(operations);
    cout << "Result: " << result << endl;

    return 0;
}
