#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int kthLargestSum(vector<int> &nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;

    vector<int> sum(nums.size() + 1, 0);
    for (int i = 1; i <= nums.size(); i++) {
        sum[i] = sum[i - 1] + nums[i - 1];
    }

    for (int i = 1; i <= nums.size(); i++) {
        for (int j = i; j <= nums.size(); j++) {
            int subarraySum = sum[j] - sum[i - 1];
            if (pq.size() < k || subarraySum > pq.top()) {
                pq.push(subarraySum);
                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }
    }

    return pq.top();
}

int main() {
    int n, k;
    cout << "Enter the size of the vector: ";
    cin >> n;
    cout << "nums[] = ";
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "k = ";
    cin >> k;

    int kthLargest = kthLargestSum(nums, k);
    cout << "Kth largest sum: " << kthLargest << endl;

    return 0;
}
