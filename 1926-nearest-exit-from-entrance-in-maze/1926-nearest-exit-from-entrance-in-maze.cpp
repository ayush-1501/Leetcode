class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
         int ans = 0;
        int N=maze.size(),M=maze[0].size();
        queue<pair<int,int>>q;
        q.push({entrance[0], entrance[1]});
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                if((i == 0 or j == 0 or i==N-1 or j ==M-1)and (i!=entrance[0] or j!=entrance[1])){
                    return ans;
                }
                maze[i][j]='+';
                for(auto k:dir){
                    int currx = i+k.first;
                    int curry = j+k.second;

                    if(currx>=0 and currx<N and curry>=0 and curry<M and maze[currx][curry]=='.'){
                        maze[currx][curry] = '+';       
                        q.push({currx, curry});
                    }
                }
            }
            
            ans++;
        }
        
        return -1;
    }
};