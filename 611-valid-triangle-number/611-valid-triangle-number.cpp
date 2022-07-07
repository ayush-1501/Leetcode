class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    int ans = 0;
    int n = nums.size();
    for (int i = n - 1; i > 1; i--){
        for (int low = 0, high = i - 1; low < high;){
            if ((nums[low] + nums[high]) > nums[i]){
                ans += (high - low);
                high--;
            }
            else
                low++;
        }
    }
    return ans;
    }
};