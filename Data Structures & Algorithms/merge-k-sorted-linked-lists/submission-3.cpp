/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(auto l:lists){
            if(l!=NULL){
                pq.push({l->val,l});
            }
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(!pq.empty()){
            auto it=pq.top();
            int value=it.first;
            ListNode* node=it.second;
            pq.pop();
            temp->next=node;
            temp=temp->next;
            if(node->next){
                pq.push({node->next->val,node->next});
            }
        }
        return dummy->next;
    }
};
