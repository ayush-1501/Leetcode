class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int>m;
        for(auto i:arr){
            m[i]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto i:m){
            pq.push({i.second,i.first});
        }
        int t=arr.size()/2,c=0,ans=0;;
        while(c<t){
            pair<int,int>p=pq.top();
            pq.pop();
            c+=p.first;
            ans++;
        }
        return ans;
    }
};