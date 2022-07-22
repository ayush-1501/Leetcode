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
    ListNode* partition(ListNode* head, int x) {
         ListNode *l = new ListNode(0);
        ListNode *r = new ListNode(0);
        
        ListNode *lptr= l;
        ListNode *rptr= r;
        
        while(head!= NULL){
            if(head->val < x){
                lptr->next = head;
                lptr= lptr->next;
            }
            else{
                rptr->next = head;
                rptr=rptr->next;
            }
            head=head->next;
        }
        
        lptr->next = r->next;
        rptr->next = NULL;
        
        return l->next;
    }
};