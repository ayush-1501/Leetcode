class Solution {
public:
    string addStrings(string num1, string num2) {
         int i = num1.length()-1;
        int j = num2.length()-1;
        string r = "";
        int k = 0, t;
        int carry = 0;
        while(i >= 0 && j >= 0){
            t = (num1[i--] - '0') + (num2[j--]-'0') + carry;
            r = (char)('0' + t%10 ) + r;
            carry = t/10;
        }
        while(i >= 0 ){
            t = (num1[i--] - '0') + carry;
            r = (char)('0' + t%10 ) + r;
            carry = t/10;
        }
        while(j >= 0){
            t = (num2[j--]-'0') + carry;
            r = (char)('0' + t%10 ) + r;
            carry = t/10;
        }
        if(carry){
            r = '1' + r;
        }
        return r;
    }
};