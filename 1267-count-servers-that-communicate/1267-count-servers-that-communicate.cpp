const int N=1e5+7;
vector<int>g(N,0);
class dsu{
  public:
    dsu(int n){
        for(int i=0;i<n;i++){
            g[i]=i;
        }
    }
    
    int find_par(int i){
        if(g[i]==i){
            return i;
        }
        return g[i]=find_par(g[i]);
    }
    void uni(int i,int j){
        int a=find_par(i);
        int b=find_par(j);
        g[a]=b;
        return;
    }
};
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<vector<int>>store;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    vector<int>temp={i,j};
                    store.emplace_back(temp);
                }
            }
        }
        
      if(store.size()==1){return 0;}
      int n=store.size();
        dsu server(n);
       unordered_map<int,vector<int>> r,c;
	    for(int i = 0; i < store.size(); i++) {
		r[store[i][0]].push_back(i);
		c[store[i][1]].push_back(i);
	   }

	
	for(int i=0;i<store.size();i++) {
		for(int j:r[store[i][0]])server.uni(i,j);
		for(int j:c[store[i][1]])server.uni(i,j);
	}
      
      map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[server.find_par(i)]++;
        }
        
        int count=0;
        for(auto i:mp){
            if(i.second!=1){
                count+=i.second;
            }
        }
        return count;
    }
};