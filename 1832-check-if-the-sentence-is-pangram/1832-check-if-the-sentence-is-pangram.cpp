class Solution {
public:
    bool checkIfPangram(string sentence) {
        map<char,int>m;
        for(auto i:sentence){
            m[i]++;
        }
        return m.size()==26;
    }
};