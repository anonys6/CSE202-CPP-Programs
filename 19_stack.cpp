class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack <int> score;
        
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
        while(!score.empty()) {
            sum += score.top();
            score.pop();
        }

        return sum;
    }
};
