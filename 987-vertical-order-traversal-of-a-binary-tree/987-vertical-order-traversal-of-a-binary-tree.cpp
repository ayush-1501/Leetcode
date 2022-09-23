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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};
        
        map<int,vector<pair<int,int>>>m;

    
        stack<tuple<TreeNode*, int, int>> st;
        st.push({root, 0, 0});
        while (!empty(st)) {
            const auto [node, row, col] = st.top(); st.pop();
            
            m[col].push_back({row, node->val});
            
            if (node->left) st.push({node->left, row + 1, col - 1});
            if (node->right) st.push({node->right, row + 1, col + 1});
        }
        

        vector<vector<int>> ans;
        for (auto& [col, v] : m) {
            sort(begin(v), end(v));
            vector<int> tmp;
            transform(begin(v),end(v),back_inserter(tmp),[](
                const pair<int,int>& p){return p.second;}
            );
            ans.push_back(move(tmp));
        }

        return ans;        
    }
};