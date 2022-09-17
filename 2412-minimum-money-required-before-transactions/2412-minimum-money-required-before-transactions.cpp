class Solution {
public:
    long long minimumMoney(vector<vector<int>>& t) {
       long long ans = 0; int v = 0;
        for (auto& a:t) {
            v = max(v,min(a[0], a[1]));
            ans+= max(a[0]-a[1], 0);
        }
        return ans + v;
    }
};