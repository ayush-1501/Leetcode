class Solution {
public:
    int minimumLength(string s) {
         int l=0,h=s.size()-1;
        while(l<h){
            char c=s[l];
            if(s[l]!=s[h])return (h-l+1);
            else{
                while(l<s.size() && s[l]==c){
                    l++;
                }
                while(h>=0 && s[h]==c){
                    h--;
                }
            }
        }
        if(l==h)return 1;
        return 0;
    }
};