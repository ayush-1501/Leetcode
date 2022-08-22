class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0){return false;}
         double x=(double)n;
        x=log10(x);
        double y=log10(3);
        return ceil(x/y) == floor(x/y);
    }
};