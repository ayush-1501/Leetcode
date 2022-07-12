class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> out(n+1,0);  //outdegree->no of edges going out from vertex
        vector<int> in(n+1,0);   //indegree->no of edges coming to the vertex   
        
        for(auto itr:trust){
            out[itr[0]]++;
            in[itr[1]]++;
        }
        
        //if outdegree is equal to zero->the person trusts no one
        //if indegree is equal to n-1->everyone trust the person
        for(int i=1;i<=n;i++){
            if(out[i]==0 && in[i]==n-1){return i;}
        }
        
        return -1;
    }
};