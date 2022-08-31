class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        for(char i:s){
            if(st.empty() and i=='*'){
                continue;
            }else if(i=='*'){
                st.pop();
            }else{
                st.push(i);
            }
        }
        string a;
        while(!st.empty()){
            a+=st.top();
            st.pop();
        }
        reverse(a.begin(),a.end());
        return a;
    }
};