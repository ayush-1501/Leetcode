//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>ans;
        vector<int>adjl[V+1];
        int intdegree[V]={0};
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                adjl[it].push_back(i);
                intdegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(intdegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            ans.push_back(node);
            
            //traverse to its nodes
            for(auto it :adjl[node])
            {
                intdegree[it]--;
                if(intdegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends