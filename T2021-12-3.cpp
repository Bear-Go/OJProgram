#include <bits/stdc++.h>

using namespace std;

enum MODE {
    UPPERCASE, LOWERCASE, NUMBER
};

int w, s;
int mode;
vector<int> data_words;

int mode_judge_get_key(char c, int& key) {
    if (c >= 'A' && c <= 'Z') {
        key = c - 'A';
        return UPPERCASE;
    }
    if (c >= 'a' && c <= 'z') {
        key = c - 'a';
        return LOWERCASE;
    }
    if (c >= '0' && c <= '9') {
        key = c - '0';
        return NUMBER;
    }
    return -1;
}

void get_date_words() {
    vector<int> words;
    char c;
    while (cin >> c) {
        int key;
        int next_mode = mode_judge_get_key(c, key);
        if (next_mode == -1) {
            exit(-1);
        }
        if (next_mode == mode) {
            words.push_back(key);
            continue;
        }
        if (mode == UPPERCASE) {
            if (next_mode == LOWERCASE) {
                words.push_back(27);
                words.push_back(key);
                mode = LOWERCASE;
                continue;
            }
            if (next_mode == NUMBER) {
                words.push_back(28);
                words.push_back(key);
                mode = NUMBER;
                continue;
            }
        }
        if (mode == LOWERCASE) {
            if (next_mode == UPPERCASE) {
                words.push_back(28);
                words.push_back(28);
                words.push_back(key);
                mode = UPPERCASE;
                continue;
            }
            if (next_mode == NUMBER) {
                words.push_back(28);
                words.push_back(key);
                mode = NUMBER;
                continue;
            }
        }
        if (mode == NUMBER) {
            if (next_mode == UPPERCASE) {
                words.push_back(28);
                words.push_back(key);
                mode = UPPERCASE;
                continue;
            }
            if (next_mode == LOWERCASE) {
                words.push_back(27);
                words.push_back(key);
                mode = LOWERCASE;
                continue;
            }
        }
    }
    if (words.size() % 2 == 1) {
        words.push_back(29);
    }
    for (int i = 0; i < words.size(); i += 2) {
        data_words.push_back(words[i] * 30 + words[i + 1]);
    }
}

void get_other_data_words() {
    int k = 0;
    if (s == -1)
        k = 0;
    else 
        k = pow(2, s + 1);
    int words_num = data_words.size() + k + 1;
    int row = 0;
    if (words_num % w == 0) 
        row = words_num / w;
    else 
        row = words_num / w + 1;
    int extra = row * w - words_num; 
    data_words.insert(data_words.begin(), row * w - k);
    for (int i = 0; i < extra; ++i) data_words.push_back(900);
}

int main() {
    int mode = UPPERCASE;
    cin >> w >> s;

    get_date_words();
    get_other_data_words();

    for (int i = 0; i < data_words.size(); i++) {
        cout << data_words[i] << endl;
    }
    return 0;
}

/*
取k次多项式 g(x)=(x-3)(x-3^2)...(x-3^k),
(n-1)次多项式 d(x)=d_{n-1}x^{n-1}+...+d_0,
找到多项式q(x)和不超过(k-1)次的多项式r(x),
使得 x^kd(x)===q(x)g(x)-r(x).
那么多项式r(x)中x的i次项系数对 929 取模后（取正值）的数字即为校验码字c_i.
*/