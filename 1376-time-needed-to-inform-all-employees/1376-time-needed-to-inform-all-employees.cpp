class Solution {
public:
     int dfs(vector<int> tree[],int vertex,vector<int>& informTime)
    {
        int ans=0;
        for(auto child:tree[vertex]){
             int k=informTime[vertex]+dfs(tree,child,informTime);
            ans=max(ans,k);
        }
        return ans;
        
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> tree[n];
        for(int i=0;i<n;i++)
        {
            if(manager[i]==-1)continue;
            tree[manager[i]].push_back(i);
        }
        return dfs(tree,headID,informTime);
    }
};