class Solution {
public:
    char And(vector<char> v){
         for(auto x : v){
            if(x=='f') return 'f';
        }
        return 't';
    }
    char Or(vector<char> v){
        for(auto x : v){
            if(x=='t') return 't';
        }
        return 'f';
    }
    bool parseBoolExpr(string e) {
        string s="";
        stack<char> st;
        for(int i=0;i<e.size();i++){
             if(e[i]!=')') st.push(e[i]);
             else{
                 vector<char> v;
                 while(st.top()!='('){
                      v.push_back(st.top()); st.pop();
                 }
                 st.pop();
                 if(st.top()=='!') {st.pop(); st.push((v[0]=='t')?'f':'t');}
                 if(st.top()=='|') {st.pop(); st.push(Or(v));}
                 if(st.top()=='&') {st.pop(); st.push(And(v));}
             }
        }
        return (st.top()=='t')?true:false;
    }
};