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
        string s;
        while (head != NULL) {
            s += head->val;
            head = head->next;
        }
        // test if a string is palindrome
        string t = s;
        reverse(t.begin(), t.end());
        return s == t;
    }
};