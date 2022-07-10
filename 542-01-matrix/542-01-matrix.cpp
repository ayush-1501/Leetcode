class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
                int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX)); //dp vector to store answer
        queue<pair<int,int>> q; //queue to store indexes
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});//push the indexes where 0 is found
                    dp[i][j] = 0;//mark those cells as 0 as it is 0 distance from 0
                }
            }
        }
        //now bfs search
        while(!q.empty()){
            
            int s = q.size();
            
            for(int i=0;i<s;i++){
                
                auto p = q.front();
                q.pop();
                
                int x = p.first;
                int y = p.second;
                //now we will check all the possible four direction and if in any direction  
                //distance from current cell is less than already presen distance for that cell change
                //that cell's distance to new distance and push this index to the queue 
                if(x+1<n && dp[x+1][y]>dp[x][y]+1){
                    q.push({x+1,y});
                    dp[x+1][y] = dp[x][y]+1;
                }
                
                if(y+1<m && dp[x][y+1]>dp[x][y]+1){
                    q.push({x,y+1});
                    dp[x][y+1] = dp[x][y]+1;
                }
                
                if(x-1>=0 && dp[x-1][y]>dp[x][y]+1){
                    q.push({x-1,y});
                    dp[x-1][y] = dp[x][y]+1;
                }
                
                if(y-1>=0 && dp[x][y-1]>dp[x][y]+1){
                    q.push({x,y-1});
                    dp[x][y-1] = dp[x][y]+1;
                }
                
            }
            
        }
        
        return dp;//return the 2d vectod we created

    }
};