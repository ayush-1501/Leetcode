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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL){return {};}
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>a;
            while(n--){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left!=NULL){q.push(temp->left);}
                 if(temp->right!=NULL){q.push(temp->right);}
                a.emplace_back(temp->val);
            }
            ans.emplace_back(a[a.size()-1]);
        }
        return ans;
    }
};