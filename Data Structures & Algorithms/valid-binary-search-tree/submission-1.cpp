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
bool isvalid(TreeNode* root,int maxi,int mini){
    if(!root)return true;
    if(root->val<=mini || root->val>=maxi)return false;
   return isvalid(root->left,root->val,mini) && isvalid(root->right,maxi,root->val);
}
    bool isValidBST(TreeNode* root) {
        int maxi=INT_MAX;
        int mini=INT_MIN;
return isvalid(root,maxi,mini);

    }
};
