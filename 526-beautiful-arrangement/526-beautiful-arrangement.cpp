class Solution {
public:
     bool checkValid( int i , int idx , int arragement){
        if( ( i % idx == 0 or idx % i == 0 ) and ((1 << idx) & arragement) == 0 ) return true;
        return false;
    }
    
    
    int helper( int i , int n , int arragement, vector<vector<int>>& dp ){
        // base case
        if( i == 1 ) return 1;
        
        if( dp[i][arragement] != -1 ) return dp[i][arragement];
        
        // recursive case
        int sum = 0;
        for( int idx = 1 ; idx <= n ; idx++ ){
            if( checkValid( i , idx , arragement) ){
                arragement = arragement | (1 << idx);
                sum += helper( i-1 , n , arragement , dp);
                arragement = arragement ^ (1 << idx);
            }
        }
        
        return dp[i][arragement] = sum;
    }
    
    
    int countArrangement(int n) {
        if(n<4)return n;
        vector<vector<int>>dp(n+1,vector<int>(pow(2,n+1),-1));
        int arragement = 0;
        return helper( n , n , arragement, dp);
    }
};