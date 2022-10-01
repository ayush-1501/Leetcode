class Solution {
public:
    bool ispal(string &s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){return false;}
            i++;j--;
        }
        return true;
    }
    bool base(int i,int n){
        string ans;
        while(n){
            ans+=n%i;
            n/=i;
        }
        reverse(ans.begin(),ans.end());
        return ispal(ans);
    }
    bool isStrictlyPalindromic(int n) {
        
        for(int i=2;i<=n-2;i++){
            if(!base(i,n)){
                return false;
            }
        }
        return true;
    }
};