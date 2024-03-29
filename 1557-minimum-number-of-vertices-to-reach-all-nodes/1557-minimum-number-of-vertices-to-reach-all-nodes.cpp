class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n,0);
        for(int i=0;i<edges.size();i++){
            indegree[edges[i][1]]++;
        }
        
        vector<int>ans;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};