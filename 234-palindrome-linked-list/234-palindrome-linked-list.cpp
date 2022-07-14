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
    bool isPalindrome(ListNode* head) {
        if(head==NULL or head->next==NULL){return true;}
        vector<int>ans;
        ListNode* ptr=head;
        while(ptr!=NULL){
            ans.emplace_back(ptr->val);
            ptr=ptr->next;
        }
        int s=0,l=ans.size()-1;
        while(s<l){
            if(ans[s]!=ans[l]){
                return false;
            }
            s++;l--;
        }
        return true;
    }
};