class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int num=1;
        for(int i=0;i<target.size();){
            if(num==target[i]){
                res.push_back("Push");
                i++;
            }
            else{
                res.push_back("Push");
                res.push_back("Pop");
            }
            num++;
        }
        return res;
    }
};