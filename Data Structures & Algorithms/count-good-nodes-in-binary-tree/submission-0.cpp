/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int count = 0;
    int goodNodes(TreeNode* root) {
        int max = INT_MIN;
        dfs(root, max);
        return count;
    }

    void dfs(TreeNode* root, int max){
        if(!root) return;
        if(root->val >= max){
            count++;
            max = root->val;
        }
        dfs(root->right, max);
        dfs(root->left, max);
    }
};
