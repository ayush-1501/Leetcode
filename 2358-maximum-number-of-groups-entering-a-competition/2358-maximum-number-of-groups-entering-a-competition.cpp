class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        if (n==0)return 0;
        int total=0;
        int groups=1;
        
        while(total<=n){
            total+=groups;
            groups++;
        }
        groups=groups-2;
        return groups;
    }
};