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
TreeNode* construct(int& idx,int start,int end,vector<int>& preorder, vector<int>& inorder){
if(start>end)return NULL;
int value=preorder[idx];
TreeNode* node=new TreeNode(value);

idx++;
int i=start;
for(;i<=end;i++){
    if(inorder[i]==value){
        break;
    }
}
node->left=construct(idx,start,i-1,preorder,inorder);
node->right=construct(idx,i+1,end,preorder,inorder);
return node;

}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
   
     int start=0;
     int end=preorder.size()-1;
     int idx=0;
     return construct(idx,start,end,preorder,inorder);
    }
};
