// 面试题 17.19. 消失的两个数字

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        long long size = (long long)nums.size() + 2;
        long long sum = size * (size + 1) / 2;
        long long square_sum = size * (size + 1) * (2 * size + 1) / 6;
        for (auto x : nums) {
            sum -= x;
            square_sum -= x * x;
        }
        long long diff = (2 * square_sum - sum * sum);
        vector<int> ans;
        ans.push_back((sum - sqrt(2 * square_sum - sum * sum)) / 2);
        ans.push_back((sum + sqrt(2 * square_sum - sum * sum)) / 2);
        return ans;
    }
};

void test1() {
    vector<int> input;
    input.push_back(1);
    Solution p;
    auto output = p.missingTwo(input);
    for (auto x : output) {
        cout << x << " ";
    }
    cout << endl;
}

void test2() {
    vector<int> input;
    input.push_back(2);
    input.push_back(3);
    Solution p;
    auto output = p.missingTwo(input);
    for (auto x : output) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    test1();
    test2();
}
