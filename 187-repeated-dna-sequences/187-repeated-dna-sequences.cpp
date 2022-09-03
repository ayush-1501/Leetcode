class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
       if(s.size()<10)return {};
        unordered_set<string>seen,repeated;
        for(int i=0;i<s.size()-9;i++){
         string subStr=s.substr(i,10);
          if(seen.count(subStr))repeated.insert(subStr);
          else seen.insert(subStr);
    }
    vector<string>ans(repeated.begin(),repeated.end());
    return ans;
    }
};