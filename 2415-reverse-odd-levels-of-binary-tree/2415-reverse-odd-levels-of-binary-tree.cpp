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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL){
            return root;
        }
    
        queue<TreeNode*>q;
        q.push(root);
         int cnt=1;
         vector<int>v;
        while(!q.empty()){
            int size=q.size();
             vector<int>vect;
            for(int i=0;i<size;i++){
                TreeNode* x=q.front();
                q.pop();
                if(cnt%2==0){
                    x->val=v[v.size()-i-1];
                }
                
                
                if(x->left!=NULL){
                    vect.push_back(x->left->val);
                    q.push(x->left);
                    
                }
                if(x->right!=NULL){
                    q.push(x->right);
                    vect.push_back(x->right->val);
                }  
                
            }
            cnt++;
            v=vect;
        }
        
        return root;
    }
};