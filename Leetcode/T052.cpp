#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* res = new TreeNode(0);
        TreeNode* cur = res;
        dfs(root, cur);
        return res->right;
    }
private:
    void dfs(TreeNode* root, TreeNode*& cur) {
        if (!root) return;
        dfs(root->left, cur);
        cur->right = new TreeNode(root->val);
        cur = cur->right;
        dfs(root->right, cur);
    }
};

int main() {

    return 0;
}

// copilot experiment