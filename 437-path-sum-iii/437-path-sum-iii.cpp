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
    int c=0;
    void dfs(TreeNode* root,int &t,long long &s){
        if(!root){return;}
        s+=root->val;
        
            if(t==s){c++;}
        dfs(root->left,t,s);
        dfs(root->right,t,s);
        s-=root->val;
    }
    void call(TreeNode* root,int &t){
        long long s=0;
        if(!root){return ;}
        call(root->left,t);
        call(root->right,t);
        dfs(root,t,s);
    }
    int pathSum(TreeNode* root, int targetSum) {
        call(root,targetSum);
        return c;
    }
};