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
    vector<int> largestValues(TreeNode* root) {
        if(!root){return {};}
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        while(!q.empty()){
            int n=q.size(),t=INT_MIN;
            while(n--){
                TreeNode* temp=q.front();
                q.pop();
                t=max(t,temp->val);
                if(temp->left!=NULL){q.push(temp->left);}
                if(temp->right!=NULL){q.push(temp->right);}
            }
            ans.emplace_back(t);
        }
        return ans;
    }
};