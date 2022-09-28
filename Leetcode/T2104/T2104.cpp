#include <bits/stdc++.h>

using namespace std;

class Solution {
    // naive version O(n^2)
    // faster version could be O(n)
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ret= 0;
        for (int i = 0; i < nums.size(); ++i) {
            int up, low;
            up = low = nums[i];
            for (int j = i; j < nums.size(); ++j) {
                up = max(up, nums[j]);
                low = min(low, nums[j]);
                ret += up - low;
            }
        }
        return ret;
    }
};

vector<int> input;
int main() {
    int tmp;
    while (cin >> tmp) input.push_back(tmp);
    
    Solution s;
    cout << s.subArrayRanges(input) << endl;

    return 0;
}