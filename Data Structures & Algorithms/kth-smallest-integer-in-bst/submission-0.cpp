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
    int kthSmallest(TreeNode* root, int k) {
       int count=0;
 int ans=-1;
        TreeNode* node=root;
       stack<TreeNode*>st;
       while(true){
        if(node!=NULL){
            st.push(node);
            node=node->left;
        }
        else{
            if(st.empty())break;
           TreeNode*value=st.top();
            st.pop();
            count++;
            ans=value->val;
            if(count==k){
                return ans;
            }
            node=value->right;
        }
       }
       return -1;
    }
};
