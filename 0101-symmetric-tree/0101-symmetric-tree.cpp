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
     bool tree(TreeNode *l,TreeNode *r)
    {
        if(!l and !r)
        {return true;}
        
        if(!l or !r)
        {return false;}
        
        return (l->val==r->val and tree(l->left,r->right) and tree(l->right,r->left));
    }
    bool isSymmetric(TreeNode* root) {
          if(!root)
          {return true;}
        
          return tree(root->left,root->right);
    }
};