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
    void helper(TreeNode* curr, int lvl, vector<vector<int>>& ans){
        if(curr == NULL){
            return;
        }
        if(lvl == ans.size()){
            ans.push_back({});
        }
        ans[lvl].push_back(curr->val);
        helper(curr->left, lvl + 1, ans);
        helper(curr->right, lvl + 1, ans);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        helper(root, 0, ans);
        return ans;
    }
};