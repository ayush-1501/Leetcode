class Solution {
public:
    vector<pair<int,int>>dir{{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int N=image.size();
        int M=image[0].size();
        int old=image[sr][sc];
        cout<<old;
        if(image[sr][sc]==color)return image;
                queue<pair<int,int>>q;
                q.push({sr,sc});
                while(!q.empty()){
                    int n=q.size();
                    while(n--){
                        pair<int,int>p=q.front();
                        q.pop();
                        image[p.first][p.second]=color;
                            for(auto k:dir){
                                int x=p.first+k.first;
                                int y=p.second+k.second;
                                
                                if(x>=0 && x<N && y>=0 && y<M and image[x][y]==old){
                                   {image[x][y]=color;
                                    q.push({x,y});
                                   } 
                                }
                        }
                    }
                }
        return image;
    }
};