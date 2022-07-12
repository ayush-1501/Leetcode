class Solution {
public:
    bool dfs(vector<int>&arr,int i,vector<int>&vis,int N){
        if(i>=N or i<0){return false;}
        if(vis[i]){return false;}
        if(arr[i]==0){return true;}
        vis[i]=1;
        bool a=dfs(arr,i-arr[i],vis,N);
        bool b=dfs(arr,i+arr[i],vis,N);
        return a||b;
    }
    bool canReach(vector<int>& arr, int start) {
        int N=arr.size();
        vector<int>vis(N,0);
        return dfs(arr,start,vis,N);
    }
};