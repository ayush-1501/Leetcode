class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string>s;
        stringstream ss(sentence);
        string k;
        while(ss>>k){
            s.emplace_back(k);
        }
        int count=1,ans=-1;
        for(auto i:s){
            if(i.find(searchWord)==0){
                return count;
            }
           count++;
        }
        return ans;
    }
};