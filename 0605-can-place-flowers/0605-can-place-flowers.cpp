class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int k) {
        int n=f.size();
        if(n==1 and f[0]==0 and k==1)return true;
        if(n==1 and f[0]==0 and k==0)return true;
        
        for(int i=0;i<n;i++){
            if(i==0 and f[i]==0 and i+1<n and f[i+1]==0){f[i]=1;k--;}
            if(i==n-1 and f[i]==0 and f[i-1]==0){f[i]=1;k--;}

            else if(i>0 and f[i]==0){
                if(i+1<n and f[i+1]==0){
                    if(i-1>=0 and f[i-1]==0){
                        k--; f[i]=1;
                    }
                }
            }
        }
        return k<=0;
    }
};