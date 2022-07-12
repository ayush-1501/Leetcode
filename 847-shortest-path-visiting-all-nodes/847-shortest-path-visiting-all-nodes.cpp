class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
      queue<pair<int, int>> q; //q stores {Node, currentMask}
        //1. Insert all nodes as source nodes, because the graph might be covered faster from one node than with the other
		
        int n = graph.size();
        for(int i=0; i<n; i++){
            int maskWithIVisited = setBit(0, i);
            q.push({i, maskWithIVisited});
        }
		
        int allVisitedMask = pow(2, n) -1; //For n= 3 -> all nodes visited = 111, i.e. 7 in decimal
        
        vector<vector<int>> visited;
		
        //Create dp. In dp, row will denote mask, col will denote the node
        //State in dp (visited) is [mask][node], any node that is not visited with current mask can be revisited, while visiting it mark it as visited -> visited[newMask][node] = 1;
        //newMask is current mask with node bit set.
        
        int row = pow(2,n); //We will be accessing 7th index for n=3 as shown above, so have 8 size.
        int col = n; 
        visited.resize(row, vector<int>(col, 0));
        
        //Perform BFS
		
        int level = 0;
        while(!q.empty()){
            int qSize = q.size();
            
            for(int i=0; i<qSize; i++){
                auto nodeMask = q.front();
                q.pop();
                int node = nodeMask.first, mask = nodeMask.second;
                if(mask == allVisitedMask) return level;

                for(auto neighbor: graph[node]){
                    //Find newMask
                    int neighborVisitedMask = setBit(mask, neighbor);
					
                    if(visited[neighborVisitedMask][neighbor] == 0){
                        //Mark visited 
                        visited[neighborVisitedMask][neighbor] = 1;
						
                        q.push({neighbor, neighborVisitedMask});
                    }
                }
            }
            level += 1;
        }
        return -1;
    }
    
private:
    int setBit(int mask, int bit){
        int res = mask | (1 << bit);
        return res;
    }
};
