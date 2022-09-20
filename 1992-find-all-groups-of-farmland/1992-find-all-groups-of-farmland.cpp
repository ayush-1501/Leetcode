class Solution {
public:
    vector<vector<int>>store;
void recur(vector<vector<int>>&land,int i,int j,int N,int M,int &dx,int &dy,vector<pair<int,int>>&pr){
        if(i<0 or j<0 or i>=N or j>=M or land[i][j]==0 or land[i][j]==2)return ;
        land[i][j]=2;
        pr.emplace_back(make_pair(i,j));
        recur(land,i+1,j,N,M,dx,dy,pr);
        recur(land,i,j+1,N,M,dx,dy,pr);
        recur(land,i-1,j,N,M,dx,dy,pr);
        recur(land,i,j-1,N,M,dx,dy,pr);
        
        
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
      int N=land.size();
        int M=land[0].size();
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(land[i][j]==1){
                    int dx=-1,dy=-1;
                    vector<pair<int,int>>pr;
                    recur(land,i,j,N,M,dx,dy,pr);
                    sort(pr.rbegin(),pr.rend());
                    // for(auto i:pr){
                    //     cout<<i.first<<" "<<i.second<<"\n";
                    // }
                    vector<int>temp={i,j,pr[0].first,pr[0].second};
                    store.emplace_back(temp);
                }
            }
        }
        return store;
    }
};