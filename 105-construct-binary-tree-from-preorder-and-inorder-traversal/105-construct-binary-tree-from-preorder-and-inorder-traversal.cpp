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
    int search(vector<int> &inorder,int start,int end,int curr)
    {
        for(int i=start;i<=end;i++)
        {
            if(inorder[i]==curr)
                return i;
        }
        return -1;
    }
    TreeNode* build(vector<int>& preorder,vector<int>& inorder,int start,int end,int &index)
    {
        if(start>end)
            return NULL;
        int current=preorder[index];
        index++;
        TreeNode* tree=new TreeNode(current);
        if(start==end)
            return tree;
        int pos=search(inorder,start,end,current);
        tree->left=build(preorder,inorder,start,pos-1,index);
        tree->right=build(preorder,inorder,pos+1,end,index);
        return tree;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        return build(preorder,inorder,0,(preorder.size()-1),index);
    }
};