const int N=1e4;
 vector<int>g(N,0);
class dsu{
public:
   dsu(int n){
      for(int i=0;i<=n;i++)g[i]=i;
   }
   int find_par(int i){
      if(i==g[i])return i;
      return g[i]=find_par(g[i]);
   }
   void uni(int i,int j){
      int a=find_par(i);
       int b=find_par(j);
       if(a==b){
           return;
       }else{
           g[a]=b;
           return;
       }
   }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        dsu a(n);
        vector<int>ans;
        for(int i=0;i<edges.size();i++){
            int first=a.find_par(edges[i][0]);
            int second=a.find_par(edges[i][1]);
            if(first!=second){
                a.uni(first,second);
            }else{
                return edges[i];
            }
            
        }
        return {};
    
    }
};