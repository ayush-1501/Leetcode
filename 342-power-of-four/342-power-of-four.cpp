class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0){return false;}
        double x=(log(n)/ log(4));
        int t=x;
        return t==x;
    }
};