class Solution {
public:
   bool dfs(int index,vector<int>& sidel,int target,vector<int>&sti){
        if(index == sti.size()){
          return sidel[0]==sidel[1]&&sidel[1]==sidel[2]&&sidel[2]==sidel[3];
        }
        
        for(int i = 0; i < 4; i++){
            if(sidel[i]+sti[index]>target)continue;
            //int j = i;
            // while(--j >= 0){
            //     if(sidel[i] == sidel[j])break;
            // }
            // if(j != -1)continue;
            
            sidel[i]+=sti[index];
            if(dfs(index+1,sidel,target,sti)){
                return true;
            }
            sidel[i]-=sti[index];
        }
        
        return false;
    }
    
    bool makesquare(vector<int>& sti) {
        int sum = 0, n = sti.size();
        for(auto it : sti)sum+=it;
        
        if(sum%4 != 0)return false;
        sort(sti.begin(), sti.end(), greater<int>());
        if(sti[0] > sum/4)return false;
        
        int target = sum/4;
        vector<int>sidel(4, 0);
        return dfs(0, sidel, target, sti);
            
    }
};