class Solution {
public:
    int longestPalindrome(vector<string>& words) {
      map<string,int> m;
        for(auto x:words)
            m[x]++;
        int ans=0,mid=0;
        for(auto x:m){
            string rev =x.first;
            reverse(rev.begin(),rev.end());
            if(m[rev]!=0){
                if(rev!=x.first)
                    ans+=4*min(m[rev],m[x.first]);
                else{
                    ans += 4*(m[x.first]/2);
                    if(m[x.first]%2)
                        mid = 1;
                }
            }
            m.erase(rev);
            m.erase(x.first);
        }
        return ans + mid*2;
    }
};