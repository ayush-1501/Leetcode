class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0;
        digits[digits.size()-1]++;
        for(int i=(int)digits.size()-1;i>=0;i--){
            if(digits[i]>9){
                digits[i]=0;carry=1;
            }
            else{
                if(digits[i]+carry>9){
                   digits[i]=0;carry=1;
                }
                else{
                    digits[i]+=carry; carry=0;
                }
            }
        }
        if(carry==1){
            vector<int>ans;
            ans.emplace_back(1);
            int n=digits.size();
            while(n--){ans.emplace_back(0);}
            return ans;
        }
        return digits;
        
    }
};