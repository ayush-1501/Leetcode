class Solution {
public:
    vector<string> graph={"abcde","fghij","klmno","pqrst","uvwxy","z****"};
    unordered_map<string,pair<int,int>>dir={{"L",{0,-1}},{"R",{0,1}},{"U",{-1,0}},{"D",{1,0}}};
    
    bool isValid(int x,int y){
        if(x>=6 || y>=5 || x<0 || y<0)return false;
        return true;
    }
    
    pair<string,pair<int,int>> bfs(int curr,int x,int y,string target){
        queue<pair<string,pair<int,int>>> q;
        q.push({"",{x,y}});
        while(!q.empty()){
            pair<string,pair<int,int>> ele=q.front();
            q.pop();
            string currStr=ele.first;
            int nx=ele.second.first;
            int ny=ele.second.second;
            if(graph[nx][ny]==target[curr]){
                return {currStr+'!',{nx,ny}};
            }
            for(auto i:dir){
                int newX=nx+i.second.first;
                int newY=ny+i.second.second;
                if(isValid(newX,newY) && graph[newX][newY]!='*'){
                    q.push({currStr+i.first,{newX,newY}});
                }
            }
        }
        return {"",{-1,-1}};
    }
    
    string alphabetBoardPath(string target) {
        if(target.size()==0)return "";
        int sx=0,sy=0;
        string ans="";
        for(int i=0;i<target.size();i++){
            pair<string,pair<int,int>>bfsans=bfs(i,sx,sy,target);
            ans+=bfsans.first;
            sx=bfsans.second.first;
            sy=bfsans.second.second;
        }
        return ans;
    }
};