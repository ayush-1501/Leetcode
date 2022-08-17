class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words){
        vector<string>st={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        map<char,string>mp;
        char alpha='a';
        for(string i:st){
            mp[alpha]=i;
            alpha++;
        }
        set<string>s;
        for(string i:words){
            string ans;
            for(char j:i){
                ans+=mp[j];
            }
            s.insert(ans);
        }
        return s.size();
    }
};