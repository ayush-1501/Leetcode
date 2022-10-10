class Solution {
public:
    string breakPalindrome(string p) {
        if(p.size()==1){return "";}
        int s=0,end=p.size()-1;
        bool flag=false;
        while(s<end){
            if(p[s]==p[end]){
                if(p[s]!='a'){
                    p[s]='a';
                    flag=true;break;
                }
            }
           s++;end--;
        }
        if(!flag){
            p.pop_back();
            p+="b";
        }
        return p;
    }
};