#include <bits/stdc++.h>

using namespace std;

char s[3000005];

vector<int> num;
vector<int> ind;

int main() {
    int cnt = 0;
    int sum = 0;
    while (1) {
        char c = getchar();
        if (c == '\n') 
            break;
        else if (c >= '0' && c <= '9') {
            sum = sum * 10 + (c - '0');
        }
        else if (c == '{') {
            num.push_back(sum);
            ind.push_back(cnt);
            sum = 0;
        }
        else if (c == '}') {
            int pos = cnt;
            for (int i = 1; i <= num.back() - 1; ++i) {
                for (int j = ind.back(); j < pos; ++j) {
                    s[cnt++] = s[j];
                }
            }
            num.pop_back();
            ind.pop_back();
        }
        else s[cnt++] = c;
    }
    for (int i = 0; i < cnt;  ++i)
        printf("%c", s[i]);
}