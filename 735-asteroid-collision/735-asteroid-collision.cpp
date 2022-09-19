class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int>ans;
        int n=a.size();
        stack<int>st;
        for(int i=0;i<n;i++){
                if(a[i]>0 or st.empty())
                    {st.push(a[i]);}
            
                else{
                     while(!st.empty() && abs(a[i])>st.top() && st.top()>0)
                     {st.pop();}
                    
                    if(!st.empty() && abs(a[i])==st.top())
                    {st.pop();}
                    
                     else {
                     if(st.empty() || st.top() < 0) {
                        st.push(a[i]);
                        }
                     }
                }
            
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};