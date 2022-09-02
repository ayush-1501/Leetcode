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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<double>>ans;
        if(root==NULL)return {};
        queue<TreeNode*>q;
        q.push(root);
          while(!q.empty()){
              int size=q.size();
              vector<double>level;
              for(int i=0;i<size;i++){
                  TreeNode* node=q.front();
                  q.pop();
                  if(node->left!=NULL)q.push(node->left);
                  if(node->right!=NULL)q.push(node->right);
                  level.push_back(node->val);   
              }
           ans.push_back(level);
      }
        vector<double>ans1;
        for(auto i:ans){
            double sum=0;
            for(int j=0;j<i.size();j++){
                sum+=i[j];
            }
            ans1.push_back(sum/i.size());
        }
        return ans1;
    }      
};