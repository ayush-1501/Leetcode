class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
       int maxx=INT_MIN,minn=INT_MAX,sum1=0,sum2=0,tsum=0;   
        for(int x:nums){
            tsum+=x;sum1+=x;sum2+=x;
            maxx=max(maxx,sum1);
            if(sum1<0) sum1=0;
            minn=min(sum2,minn);
            if(sum2>0) sum2=0;
        }
        if(tsum==minn) return maxx;        
        else return max(maxx,tsum-minn); 
    }
};