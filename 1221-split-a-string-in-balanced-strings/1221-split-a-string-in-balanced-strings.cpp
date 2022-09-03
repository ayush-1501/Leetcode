class Solution {
public:
    int balancedStringSplit(string s) {
        int c=0;
        stack<char>st;
        for(auto i:s){
            if(st.empty()){
                st.push(i);
                c++;
            }
            else if(st.top()=='R'){
                if(i=='L'){
                    st.pop();
                }
                else{
                    st.push(i);
                }
            }
             else if(st.top()=='L'){
                if(i=='R'){
                    st.pop();
                }
                else{
                    st.push(i);
                }
            }
        }
        return c;
    }
};