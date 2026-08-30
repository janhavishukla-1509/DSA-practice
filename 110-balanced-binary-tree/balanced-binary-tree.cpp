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
    int helper(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftDist = helper(root->left);
        if(leftDist == -1) return -1;
        int rightDist = helper(root->right);
        if(rightDist == -1) return -1;
        if(abs(leftDist - rightDist) > 1) return -1;
        return 1 + max(leftDist, rightDist);
    }
    bool isBalanced(TreeNode* root) {
        
        return helper(root) != -1;
    }
};