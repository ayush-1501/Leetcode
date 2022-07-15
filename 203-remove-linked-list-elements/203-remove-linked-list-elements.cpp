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
    ListNode* removeElements(ListNode* head, int val) {
       if(head==NULL){
            return NULL;
        }
       while(head->val==val){
          if(head->next==NULL){head=NULL; break;}
           head=head->next;
       }
        ListNode* l=head,*prev;
        while(l!=NULL and l->next!=NULL){
            prev=l;
            if(l->next->val==val){
                l->next=l->next->next;
                l=prev;continue;
            }
            l=l->next;
        }

        return head;
    }
};