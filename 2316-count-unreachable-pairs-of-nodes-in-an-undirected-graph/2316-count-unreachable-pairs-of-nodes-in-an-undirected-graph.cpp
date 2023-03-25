const int N=2e5+10;
class Solution {
    vector<int>g[N];
    bool vis[N];
    vector<vector<int>>cc;
    vector<int>current_cc;
public:
  
    
    void dfs(int vertex,vector<int>g[]){
        vis[vertex]=true;
        current_cc.push_back(vertex);
        
        for(int child:g[vertex]){
            if(vis[child]){continue;}
            dfs(child,g);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        int ct=0;
        
        for(int i=0;i<n;i++){
            vis[i]=false;
        }
        for(int i=0;i<edges.size();i++){
            int x,y;
            x=edges[i][0];y=edges[i][1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        for(int i=0;i<n;i++){
            if(vis[i]){continue;}
            current_cc.clear();
            dfs(i,g);
            cc.push_back(current_cc);
            ct++;
        }
        if(cc.size()==1){return 0;}
        if(cc.size()==n){return (long long)(n*(long long)(n-1))/2;}
        vector<long long>ans(cc.size());
        int i=0;
        for(auto c_cc:cc){
            long long count=0;
            for(int vertex:c_cc){
                count++;
            }
            ans[i++]=count;
        }
       long long ans1=(long long)n*(long long)n;
        //for(auto i:ans){cout<<i<<" ";}
        for(int i=0;i<ans.size();i++){
            ans1-=ans[i]*ans[i];
        }
        return (ans1)/2;
    }
};