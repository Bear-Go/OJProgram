#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        if (!root) return {};
        int num = root->children.size();
        if (num == 0) {
            return {root->val};
        }
        vector<int> res;
        for (int i = 0; i < num; ++i) {
            vector<int> tmp = postorder(root->children[i]);
            for (int j = 0; j < tmp.size(); ++j) {
                res.push_back(tmp[j]);
            }
        }
        res.push_back(root->val);
        return res;
    }
};

int main() {

    Solution s;
    

    return 0;
}