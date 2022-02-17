#include <bits/stdc++.h>

using namespace std;

map<string, int> di; // dictionary
vector<string> re; // reference
int tot = 0; // total

vector<int> res; // result

#define N 1000005
struct Node {
    int t, n;
} e[N][2];

int head[N][2];
int t[2] = {0, 0};

bool vis[N][2]; // is vis
bool has[N][2]; // has ','

void add(int from, int to) {
    e[t[0]][0].t = to;
    e[t[0]][0].n = head[from][0];
    head[from][0] = t[0]++;
    e[t[1]][1].t = from;
    e[t[1]][1].n = head[to][1];
    head[to][1] = t[1]++;
}

void dfs(int x, int dir) {
    vis[x][dir] = 1;
    has[x][dir] = 1;
    for (int i = head[x][dir]; ~i; i = e[i][dir].n) {
        int in = e[i][dir].t;
        if (vis[in][dir ^ 1]) continue;
        dfs(in, dir ^ 1);
    }
}

int main(){
    // init mapping
    memset(head, -1, sizeof(head));
    re.push_back(".");
    string word;
    while (1) {
        char c = getchar();
        if (c == '.' || c == ',' || c == ' ') {
            if (!word.empty()) {
                if (di.find(word) == di.end()) {
                    ++tot;
                    di[word] = tot;
                    re.push_back(word);
                }
                res.push_back(di[word]);
            }
            if (c == '.')
                res.push_back(0);
            else if (c == ',')
                res.push_back(-1);
            word.clear();
        }
        else if (c == '\n') 
            break;
        else
            word += c;
    }
    // construct the graph
    int len = res.size();
    for (int i = 0; i < len; ++i) {
        if (i >= 1 && res[i - 1] > 0 && res[i] > 0) {
            // ' ' before this word
            add(res[i - 1], res[i]);
        }
        else if (i >= 2 && res[i - 2] > 0 && res[i] > 0 && res[i - 1] == -1) {
            // ',' before this word
            add(res[i - 2], res[i]);
            has[res[i - 2]][0] = 1;
            has[res[i]][1] = 1;
        }
    }
    // travel
    for (int i = 1; i <= tot; ++i) {
        if (!vis[i][0] && has[i][0]) dfs(i, 0);
        if (!vis[i][1] && has[i][1]) dfs(i, 1);
    }
    // reconstruct
    for (int i = 0; i < len; ++i) {
        if (i && res[i - 1] > 0 && res[i] > 0 && (has[res[i - 1]][0] || has[res[i]][1]))
            printf(",");
        if (res[i] == -1)
            printf(",");
        else if (res[i] == 0) 
            printf(".");
        else {
            if (i)  printf(" ");
            cout << re[res[i]];
        }
    }
}