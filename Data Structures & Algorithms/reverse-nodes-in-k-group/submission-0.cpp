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
ListNode* reverse(ListNode* head){
    ListNode* curr=head;
     ListNode* temp=head;
    ListNode* prev=NULL;
    while(curr){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}
ListNode* knode(ListNode* head,int k){
    ListNode* curr=head;
    k=k-1;
    while( curr && k){
curr=curr->next;
k--;
    }
    return curr;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(temp){
        ListNode* kthnode=knode(temp,k);
        if(kthnode==NULL){
      if(prev)prev->next=temp;
            break;
        }
        ListNode* newnode=kthnode->next;
        kthnode->next=NULL;
        reverse(temp);
        if(temp==head){
            head=kthnode;
        }
        else{
            prev->next=kthnode;   
        }
            prev=temp;
            temp=newnode;

        }
        return head;
 

    }
};
