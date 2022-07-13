class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long c1=max(cost1,cost2);
        long long c2=min(cost1,cost2);
        long long ans=0;
        while(total>=0){
            long long t=(long long)total/c2;
            ans+=t+1;
            total-=c1;
        }
        return ans;
    }
};