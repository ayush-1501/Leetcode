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
    int post(TreeNode* root,int &s){
        if(!root){return 0;}
        post(root->left,s);
        post(root->right,s);
         if(root&&root->val%2==0){
            if(root->left&&root->left->left)
                s+=root->left->left->val;
            if(root->left&&root->left->right)
                s+=root->left->right->val;
            if(root->right&&root->right->right)
                s+=root->right->right->val;
            if(root->right&&root->right->left)
                s+=root->right->left->val;
        }
        return s;
    }
    int sumEvenGrandparent(TreeNode* root) {
        int s=0;
        return post(root,s);
    }
};