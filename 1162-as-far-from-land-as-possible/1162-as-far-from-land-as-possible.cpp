class Solution 
{
    bool isValid(int n, int r, int c)
    {
        return r >= 0 && r < n && c >= 0 && c < n;
    }
  public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        queue<std::pair<int, int>>q;
        vector<std::vector<int>> dp(grid.size(), std::vector<int>(grid.size(), INT_MAX));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid.size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    dp[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        vector<pair<int,int>>dir={{0,-1},{-1,0},{0,1},{1,0}};
        while (!q.empty())
        {
            pair<int, int>p= q.front();
            q.pop();
            
            for (auto k:dir)
            {
                int next_r = p.first + k.first;
                int next_c = p.second + k.second;
                
                if (isValid(grid.size(), next_r, next_c) && grid[next_r][next_c] == 0)
                {
                    if (1 + dp[p.first][p.second] < dp[next_r][next_c])
                    {
                        dp[next_r][next_c] = 1 + dp[p.first][p.second];
                        q.push({next_r, next_c});
                    }
                }
            }
        }
        
        int res = -1;
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