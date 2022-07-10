class Solution {
    int count=0;
public:
    void dfs(vector<vector<int>>& rooms,int vertex,vector<int>&visited){
        visited[vertex]=1;
        count++;
        for(int child:rooms[vertex]){
            if(visited[child])continue;
            dfs(rooms,child,visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int>visited(rooms.size(),0);
        count=0;
        dfs(rooms,0,visited);
        return count==rooms.size();
    }
};