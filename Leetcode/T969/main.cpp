#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int main() {

    int x;
    while (cin >> x) {
        arr.push_back(x);
    }

    vector<int> ans;
    vector<int> s(arr);
    sort(s.begin(), s.end());

    for (int i = s.size() - 1; i >= 1; --i) {
        for (int j = 0; j <= i; ++j) {
            if (arr[j] == s[i]) {
                ans.push_back(j + 1);
                ans.push_back(i + 1);
                reverse(arr.begin(), arr.begin() + j + 1);
                reverse(arr.begin(), arr.begin() + i + 1);
                break;
            }
        }
    }


    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }

    return 0;
}