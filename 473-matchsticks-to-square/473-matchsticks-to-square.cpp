class Solution {
public:
   bool dfs(int index, vector<int>& sideLength, int target, vector<int>&sti){
        if(index == sti.size()){
            return sideLength[0] == sideLength[1] && sideLength[1] == sideLength[2] && sideLength[2] == sideLength[3];
        }
        
        for(int i = 0; i < 4; i++){
            if(sideLength[i] + sti[index] > target)continue;
            
			
            int j = i;//Second Optimisation if the same length is present don't need to check again
            while(--j >= 0){
                if(sideLength[i] == sideLength[j])break;
            }
            if(j != -1)continue;
            
            sideLength[i] += sti[index];
            if(dfs(index+1, sideLength, target, sti)){
                return true;
            }
            sideLength[i] -= sti[index];
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& sti) {
        int sum = 0, n = sti.size();
        for(auto it : sti)sum+=it;
        
        if(sum%4 != 0)return false;
        //First Optimisation
        sort(sti.begin(), sti.end(), greater<int>());
        if(sti[0] > sum/4)return false;
        
        int target = sum/4;
        vector<int>sideLength(4, 0);
        return dfs(0, sideLength, target, sti);
            
    }
};