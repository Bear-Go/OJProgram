// love rrz
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int alphabet[100][26];
        memset(alphabet, 0, sizeof(alphabet));
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].length(); ++j) {
                alphabet[i][words[i][j] - 'a']++;
            }
        }

        vector<string> ret;
        for (int letter = 0; letter < 26; ++letter) {
            int least = 100;
            for (int i = 0; i < words.size(); ++i) {
                least = min(alphabet[i][letter], least);
            }
            string str;
            char t = 'a' + letter;
            str += t;
            for (int i = 0; i < least; ++i) {
                ret.push_back(str);
            }
        }
        return ret;
    }
};

int main() {

    Solution s;
    vector<string> words = {"bella","label","roller"};
    vector<string> ans =  s.commonChars(words);
    for (auto i:ans) {
        cout << i << " ";
    }
    return 0;
}