class Solution {
public:
     //check those elements which are not present in any of the cycle
    // DFS function to check for directed graph have cycle and its presented elements
     bool dfs(int i,vector<bool>& visited,vector<bool>&       dfsvisited,vector<bool>&present_cycle,vector<vector<int>>&graph)
  {
      visited[i]=true;
      dfsvisited[i]=true;
    
      for(auto it:graph[i])
      {
          if(!visited[it])
          {
              if(dfs(it,visited,dfsvisited,present_cycle,graph))
              return present_cycle[i]=true;
              
              /*
              reason that present[i] is true 
              but present [it] is not because
              when we start our journey from i 
              and if we found that i is coming in any cycle late
              then i is marked as true and current it will also be i at some
              time and hence it will also marked as true 
              */
          }
          else if(visited[it]==true && dfsvisited[it]==true)
          return present_cycle[i]=true;
      }
      dfsvisited[i]=false;
      return false;
  }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       vector<int> ans;
        int n=graph.size();
        vector<bool> visited(n,false),dfsvisited(n,false),present_cycle(n,false);
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,visited,dfsvisited,present_cycle,graph);
  
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!present_cycle[i]) ans.push_back(i);
        }
        return ans;
        
        
    }
};