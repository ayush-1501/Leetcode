class Solution {
public:
    int longestPalindrome(string s) {
         int ans=0;
        bool odd=false;
        map<char,int> mp;
        for(auto i:s) mp[i]++;
        for(auto i:mp){
            int temp=i.second;
            ans+=(temp/2)*2;
            if(temp%2!=0 and odd==false){
                ans++;
                odd=true;
            }
        }
        return ans;
    }
};