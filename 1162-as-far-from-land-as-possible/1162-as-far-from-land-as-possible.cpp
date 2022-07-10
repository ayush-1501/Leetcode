class Solution 
{
    bool isValid(int n, int r, int c)
    {
        return r >= 0 && r < n && c >= 0 && c < n;
    }
  public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        queue<pair<int, int>>q;
        //creating a 2D dp of grid.size()xgrid.size()
        vector<std::vector<int>> dp(grid.size(), std::vector<int>(grid.size(), INT_MAX));
       
        //storing all the points [i][j] from where bfs would be done
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid.size(); j++){
                if (grid[i][j] == 1){
                    dp[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        //for moving either to adjacent left ,right,up or down
        vector<pair<int,int>>dir={{0,-1},{-1,0},{0,1},{1,0}};
        while (!q.empty()) {
            pair<int, int>p= q.front();
            q.pop();
            
            for (auto k:dir){
                int x = p.first + k.first;
                int y = p.second + k.second;
                
                //checking if the nect co-ordinate [x][y] is valid or not
                if (isValid(grid.size(),x,y) && grid[x][y] == 0){
                    //minimizing the distance from 1 to all the reachable 0's
                    if (1 + dp[p.first][p.second] < dp[x][y]){
                        dp[x][y] = 1 + dp[p.first][p.second];
                        q.push({x,y});
                    }
                }
            }
        }
        
        int res = -1;
        //finding maximum of all the distances
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid.size(); j++){
                if (dp[i][j] != 0 && dp[i][j] != INT_MAX){
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res;
    }
};