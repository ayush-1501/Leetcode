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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){return {};}
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        vector<int>temp;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode* t=q.front();
                q.pop();
                temp.emplace_back(t->val);
                if(t->left!=NULL){q.push(t->left);}
                if(t->right!=NULL){q.push(t->right);}
            }
            ans.emplace_back(temp);
            temp.clear();
        }
        return ans;
    }
};