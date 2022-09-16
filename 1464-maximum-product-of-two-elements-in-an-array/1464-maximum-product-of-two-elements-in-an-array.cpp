class Solution {
public:
    int maxProduct(vector<int>& nums) {
      priority_queue<int>pq(nums.begin(),nums.end());
        int t=pq.top();
        pq.pop();
        int q=pq.top();
        return (t-1)*(q-1);
    }
};