#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    // naive version
    int bestRotation(vector<int>& nums) {
        int maxscore = 0, k = 0;
        for (int i = 0; i < nums.size(); i++) {
            int score = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] <= j) {
                    score++;
                }
            }
            if (score > maxscore) {
                maxscore = score;
                k = i;
            }
            int head = nums[0];
            nums.erase(nums.begin());
            nums.push_back(head);
        }
        return k;
    }

};

class Solution2 {
public:
    // faster version
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n, 0);
        for (int i = 0; i < n; ++i) {
            int low = (i + 1) % n;
            int high = (i - nums[i] + n + 1) % n;
            diff[low]++; diff[high]--;
            if (low >= high) diff[0]++;
        }
        int bestIndex = 0, maxScore = 0, score = 0;
        for (int i = 0; i < n; ++i) {
            score += diff[i];
            if (score > maxScore) {
                bestIndex = i;
                maxScore = score;
            }
        }
        return bestIndex;
    }
};

int main() {

    Solution2 s;
    vector<int> nums1 = {2,3,1,4,0};
    cout << s.bestRotation(nums1) << endl;
    vector<int> nums2 = {1,3,0,2,4};
    cout << s.bestRotation(nums2) << endl;

    return 0;
}