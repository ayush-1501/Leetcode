class Solution {
public:
    string frequencySort(string s) {
       map<char,int>m;
        for(auto i:s){
            m[i]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto i:m){
            pq.push({i.second,i.first});
        }
        string ans;
        while(!pq.empty()){
            auto t=pq.top();
            for(int i=0;i<t.first;i++){
                ans+=t.second;
            }
            pq.pop();
        }
        return ans;
    }
};