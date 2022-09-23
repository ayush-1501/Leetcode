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
    void inorder(TreeNode* root,vector<int>&store){
        if(!root){return;}
        inorder(root->left,store);
        store.emplace_back(root->val);
        inorder(root->right,store);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>store;
        inorder(root,store);
        return store;
    }
};