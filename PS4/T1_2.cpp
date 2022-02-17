#include <bits/stdc++.h>

using namespace std;

char s[55];

bool is_aeiou(char x) {
    if (x == 'a' || x == 'A' || x == 'e' || x == 'E' || x == 'i' || x == 'I' || x == 'o' || x == 'O' || x == 'u' || x == 'U')
        return true;
    else return false; 
}

bool is_abc(char x) {
    if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z')) 
        return true;
    else return false;
}

int main() {
    int cnt = 0;
    while (1) {
        s[cnt] = getchar();
        if (s[cnt] == '\n') {
            break;
        }
        ++cnt;
    }

    int num = 0;
    for (int i = 0; i < cnt; ++i) {
        if (is_abc(s[i])) {
            printf("%c", '.');
            ++num;
        }
        else 
            printf("%c", s[i]);
    }
    printf("\n");

    int j = 1;
    int num2 = ((float)num / 3) + 0.5;
    for (int i = 0; i < cnt; ++i) {
        if (is_abc(s[i])) {
            if (j > num2) {
                printf("%c", '.');
            }
            else {
                printf("%c", s[i]);
                ++j;
            }
        }
        else 
            printf("%c", s[i]);
    }
    printf("\n");

    j = 1;
    bool has_aeiou = false;
    for (int i = 0; i < cnt; ++i) {
        if (is_abc(s[i])) {
            if (j <= num2) {
                ++j;
            }
            else {
                if (is_aeiou(s[i]))
                    has_aeiou = true;
            }
        }
    }

    if (has_aeiou) {
        j = 1;
        for (int i = 0; i < cnt; ++i) {
            if (is_abc(s[i])) {
                if (j <= num2) {
                    printf("%c", s[i]);
                    ++j;
                }
                else {
                    if (is_aeiou(s[i]))
                        printf("%c", s[i]);
                    else
                        printf("%c", '.');
                }
            }
            else 
                printf("%c", s[i]);
        }
    }
    else {
        int j = 1;
        int num3 = ((float)num * 2) / 3 + 0.5;
        for (int i = 0; i < cnt; ++i) {
            if (is_abc(s[i])) {
                if (j > num3) {
                    printf("%c", '.');
                }
                else {
                    printf("%c", s[i]);
                    ++j;
                }
            }
            else 
                printf("%c", s[i]);
        }
    }
    printf("\n");
}
