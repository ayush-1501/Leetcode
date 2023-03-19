class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
            sort(nums.begin() , nums.end());  
    
    if(nums.size() < 3)   
        return {};    
    
    if(nums[0] > 0)   
        return {} ;   
    
    unordered_map<int , int> umap;
    
    for(int i = 0 ; i < nums.size() ; i++)
    umap[nums[i]] = i;  
    
    vector<vector<int>> res;
    
    for(int i = 0 ; i < nums.size() - 2 ;i++)  
    {
        if(nums[i]>0)  
            break;    
        for(int j = i+1 ; j < nums.size() - 1 ; j++)
        {
            int third = -1*(nums[i]+nums[j]);
             if(umap.count(third) and umap.find(third)->second > j)  
              res.push_back({nums[i] , nums[j] ,third});
            
            j = umap.find(nums[j])->second; 
        }
        i = umap.find(nums[i])->second;
    }
    return res;
    }
};