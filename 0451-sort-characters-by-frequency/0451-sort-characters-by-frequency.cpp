class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char,int> mp;
        for(auto i:s)
        {
            mp[i]++;
        }
        priority_queue<pair<int,char>> q;
        for(auto i:mp)
        {
            q.push({i.second,i.first});
        }
        string s1;
        while(!q.empty())
        {
            pair<int,char> p=q.top();
            for(int i=0;i<p.first;i++)
            {
                s1+=p.second;
            }
            q.pop();
        }
        return s1;

        
    }
};