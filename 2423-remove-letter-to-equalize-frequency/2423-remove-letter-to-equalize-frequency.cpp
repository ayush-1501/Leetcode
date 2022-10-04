class Solution {
public:
    bool equalFrequency(string word) {
         for(int i=0;i<word.size();i++) 
        {
            unordered_map<char,int>mp;
            unordered_map<int,int>freq;
            for(int j=0;j<word.size();j++){
                if(j!=i)
                    mp[word[j]]++;
            }
            
            for(auto it:mp)
                freq[it.second]++;
            
            if(freq.size()==1)  
                return true;
         }
        
        return false;
    }
};