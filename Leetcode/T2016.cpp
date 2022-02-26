#include <bits/stdc++.h>

using namespace std;

int t;
vector<int> nums;
int main() {
    while (cin >> t) {
        nums.push_back(t);
    }
    
    int min = (1e9+7), dif = -1;
    for (auto x: nums) {
        if (x <= min)
            min = x;
        else
            if (x - min > dif) 
                dif = x - min;
    }
    cout << dif << endl;

    return 0;
}