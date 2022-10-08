const int N=1e4;
 vector<int>g(N,-1);

class dsu{
public:
   dsu(int n){
      for(int i=0;i<n;i++)g[i]=i;
   }
   int find_par(int i){
      if(i==g[i])return i;
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
    int removeStones(vector<vector<int>>& stones) {
        if(stones.size()==1){return 0;}
        int n=stones.size();
        dsu stone(n);
       unordered_map<int,vector<int>> r,c;
	    for(int i = 0; i < stones.size(); i++) {
		r[stones[i][0]].push_back(i);
		c[stones[i][1]].push_back(i);
	   }

	
	for(int i=0;i<stones.size();i++) {
		for(int j:r[stones[i][0]])stone.uni(i,j);
		for(int j:c[stones[i][1]])stone.uni(i,j);
	}

        set<int>st;
        for(int i=0;i<n;i++){
            st.insert(stone.find_par(i));
        }
        return stones.size()-st.size();
    }
};