class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int t=__builtin_popcount(num2),ans=0;
        for(int i=31;i>=0 and t;i--){
            if(num1&(1<<i)){
                ans|=1<<i;
                t--;
            }
        }
        
        for(int i=0;i<=31 and t;i++){
            if((ans&(1<<i))==0){
                ans|=1<<i;
                t--;
            }
        }
     return ans;
    }
};