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
void countgoodnodes(TreeNode* root,int maxi,int& count){
    if(root==NULL)return ;
    if(root->val>=maxi){
        count++;
        maxi=root->val;
    }
    countgoodnodes(root->left,maxi,count);
    countgoodnodes(root->right,maxi,count);



}
    int goodNodes(TreeNode* root) {
       int count=0;
       if(!root)return count;
       countgoodnodes(root,root->val,count);
       return count;

    }
};
