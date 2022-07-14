class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans ;
        int sum =0;
        int i = num.size()-1;
        
        while(i>=0 || k!=0 || sum>0){
            if(k!=0){
                sum += k%10;
                k = k/10;
            }
             if(i>=0){
                 sum+= num[i];
                 i--;
             }
            ans.push_back(sum%10);
            sum = sum/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};