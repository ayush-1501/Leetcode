class Solution {
public:
    void solve(vector<int>&cookies,int &k,int i,int &ans,vector<int>&allocate){
        
        if(i==cookies.size()){
            int maxi=INT_MIN;
            for(int t=0;t<k;t++){
                maxi=max(allocate[t],maxi);
            }
            ans=min(maxi,ans);
            return;
        }
        
        for(int j=0;j<k;j++){
            allocate[j]+=cookies[i];
            solve(cookies,k,i+1,ans,allocate);
            allocate[j]-=cookies[i];
            if(allocate[j]==0)break;
        }
       // return;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>allocate(k,0);
        int ans=INT_MAX;
        solve(cookies,k,0,ans,allocate);
        return ans;
    }
};