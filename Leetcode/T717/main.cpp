#include <bits/stdc++.h>

using namespace std;

vector<int> bits;
int main() {
    int x;
    while (cin >> x) {
        bits.push_back(x);
    }

    bool ans = false;   
    int p = 0;
    while (p < bits.size()) {
        if (p == bits.size() - 1) {
            ans = bits[p] == 0 ? true : false; 
            break;
        }
        else if (bits[p])
            p += 2;
        else 
            p++;
    }

    cout << (ans ? "true" : "false") << endl;
    return 0;
}