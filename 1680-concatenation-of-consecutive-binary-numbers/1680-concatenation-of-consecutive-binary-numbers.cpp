class Solution {
public:
     int mod=1e9+7;
   // map<int,string>mp;
    string calc(int n){
     string str="";
        for(int i=n;i>=1;--i){
            int no=i;
            while(no){
                str+=(no%2)+'0';
                no/=2;
            }
        }
        return str;
    }
    int concatenatedBinary(int n) {
        
        string ans=calc(n);

        int res=0;
        int k=1;

        for(int i=0;i<ans.size();i++){
            int t=ans[i]-'0';
            res=(res+k*t)%mod;
            k*=2;
            k%=mod;
        }
        return res;
    }
};