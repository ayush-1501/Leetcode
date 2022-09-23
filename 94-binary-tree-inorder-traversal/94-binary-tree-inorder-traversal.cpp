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
    vector<int> inorderTraversal(TreeNode* root) {
         stack<TreeNode*> st;
        vector<int> ans;
        
        TreeNode* currNode = root;
        while (currNode or !st.empty()) {
            while (currNode) {
                st.push(currNode);
                currNode = currNode->left;
            }   

            currNode = st.top();
            st.pop();
            
            ans.push_back(currNode->val);
            currNode = currNode->right;
        }
        return ans;
    }
};