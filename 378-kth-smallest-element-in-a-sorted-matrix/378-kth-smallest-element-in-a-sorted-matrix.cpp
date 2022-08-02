class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
       multiset<int>s;
        for(auto i:matrix){
            for(int j:i){
                s.insert(j);
            }
        }
        auto it = s.begin();
        for (int i=0; i <k-1;i++)
          it++;
        return *it;
    }
};