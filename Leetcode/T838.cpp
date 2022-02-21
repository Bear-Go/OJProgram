#include <bits/stdc++.h>

using namespace std;

string dominoes;
int main() {
    cin >> dominoes;
    
    queue<int> q;
    int i = 0, length = dominoes.length();
    while (i < length) {
        if (dominoes[i] == 'L' || dominoes[i] == 'R') q.push(i);
        i++;
    }

    while (!q.empty()) {
        int size = q.size();
        queue<int> Lwait;
        queue<int> Rwait;
        for (int i = 0; i < size; ++i) {
            int pos = q.front();
            q.pop();
            cout << "pop " << pos << endl;
            switch (dominoes[pos]) {
            case 'L':
                if (pos >= 1 && dominoes[pos-1] == '.') {
                    if (pos == 1) dominoes[0] = 'L';
                    if (pos >= 2 && dominoes[pos-2] != 'R') Lwait.push(pos-1);
                }
                break;
            case 'R':
                cout << "   case: R" << endl;
                if (pos <= length-2 && dominoes[pos+1] == '.') {
                    if (pos == length-2) dominoes[length-1] = 'R';
                    if (pos <= length-3 && dominoes[pos+2] != 'L') Rwait.push(pos+1);
                }
                break;
            }
        }
        while (!Lwait.empty()) {
            q.push(Lwait.front());
            dominoes[Lwait.front()] = 'L';
            Lwait.pop();
        }
        while (!Rwait.empty()) {
            q.push(Rwait.front());
            dominoes[Rwait.front()] = 'R';
            Rwait.pop();
        }
    }
    
    
    cout << dominoes << endl;
    return 0;
}