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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* h=head,*first,*second;
        int count=0,one=1;
        while(h!=NULL)
        {count++;h=h->next;}
        h=head;
        cout<<count;
        while(h!=NULL)
        {
            if(one==k)
            {first=h;}
            if(one==count-k+1)
            {second=h;}
            one++;h=h->next;
        }
       // cout<<first->val<<"\t"<<second->val;
        int temp;
        temp=first->val;
        first->val=second->val;
        second->val=temp;
        
        
        
        
        return head;
    }
};