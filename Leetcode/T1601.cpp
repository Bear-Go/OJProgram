#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumRequirement(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res += i;
        }
        return res;
    }
};


int main() {

    

    return 0;
}