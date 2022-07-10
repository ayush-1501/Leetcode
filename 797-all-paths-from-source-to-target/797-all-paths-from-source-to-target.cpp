class Solution {
public:
    void dfs(vector<vector<int>>& graph,int vertex,vector<vector<int>>& ans,vector<int>&ds){
      ds.push_back(vertex);
        
      if(vertex==graph.size()-1){
          ans.push_back(ds);
      }
        
      for(auto child:graph[vertex]){
            dfs(graph,child,ans,ds);
      }
        
     ds.pop_back();
  }
    
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<vector<int>>ans;
    vector<int>ds;
    dfs(graph,0,ans,ds);
    return ans;
  }
};