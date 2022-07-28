class Solution {
public:
    int minSteps(string s, string t) {
        int s_size=s.size(),t_size=t.size();
        map<char,int>m;
        for(char &i:s){
            m[i]++;
        }
        for(char &i:t){
            if(!m.count(i)){m[i]++;}
            if(m[i]>1)m[i]--;
            else m.erase(i);
        }
        int count=0;
        for(auto i:m){
            count+=i.second;
        }
        return count;
    }
};