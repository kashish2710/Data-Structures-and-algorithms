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
unordered_map<TreeNode* ,int>mpp;
int solve(TreeNode* root){
if(!root)return 0;
if(mpp.count(root))return mpp[root];
int pick=root->val;
if(root->left){
    pick+=solve(root->left->left);
    pick+=solve(root->left->right);  
}
if(root->right){
    pick+=solve(root->right->left);
    pick+=solve(root->right->right);
}
int skip=solve(root->left)+solve(root->right);
return mpp[root]=max(pick,skip);
}
    int rob(TreeNode* root) {
        if(!root)return 0;
        return solve(root);
    }
};