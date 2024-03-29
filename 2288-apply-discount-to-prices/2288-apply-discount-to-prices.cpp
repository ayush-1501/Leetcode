class Solution {
public:
   bool isValid(string s){
        if(s.size() <= 1) return false;
        if(s[0] != '$') return false;
        for(int i=1; i<s.size(); i++){
            if(!isdigit(s[i])) return false;
        }
        return true;
    }
    
    string discountPrices(string sentence, int discount) {
        stringstream ss(sentence);
        string s;
        string ans="";
        while(ss>>s){
            if(isValid(s)){
                long long val = stoll(s.substr(1));
                ans += "$";
                double d = val*1.0 - ((val * discount * 1.0) / 100);
                stringstream df;
                df << fixed << setprecision(2) << d;
                ans += df.str(); 
            }
            else{
                ans += s;
            }
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};