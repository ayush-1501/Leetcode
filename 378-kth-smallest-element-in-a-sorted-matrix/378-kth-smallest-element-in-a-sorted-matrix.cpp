class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto i:matrix){
            for(int j:i){
                pq.push(j);
            }
        }
    
        while(k-1>0){
            pq.pop();k--;
        }
        return pq.top();
    }
};