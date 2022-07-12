//vis[x][0] --> visited the position x following forward direction 
//vis[x][1] --> visited the position x following backward direction 
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
         queue<pair<int,int>>q;//q{pos,dir} [0->forward,1->backward]
         q.push({0,0}); // adding starting postion with direction as forward (0)
         int end=10000; // constraint(can't go further than this)
         vector<vector<int>>vis(end+1,vector<int>(2,0));
        
        // visit the all forbidden zone
        for(auto zone:forbidden){
            if(zone<=end)vis[zone][0]=true;
            if(zone<=end)vis[zone][1]=true;
        }
        
        if(vis[x][0])return -1; // if home is at forbidden zone
        
        //starting point is both forward and backward visited(if we reach starting point in    
        //backward direction then we can't go any further because forward of starting was already marked
        //in the begenning) and hence it will be endless cycle
        vis[0][0]=true,vis[0][1]=true;
        
        
        int jumps=0;
        
        while(!q.empty()){
            int size=q.size();
            while(size--){
                pair<int,int>p=q.front();
                q.pop();
                
                int pos=p.first;
                int dir=p.second;
                
                if(pos==x)return jumps;//destination reached
                
                 // if this position is travelled with forward direction then we can move forward as   
                 // well as backward direction.
                if(dir==0){ 
                    if(((pos+a)<=end)&&(!vis[pos+a][0])){vis[pos+a][0]=true;q.push({pos+a,0});}
                    if(((pos-b)>=0)&&(!vis[pos-b][1])){vis[pos-b][1]=true;q.push({pos-b,1});}
                        
                }
                // if this position is travelled with backward direction then we can move only in 
                //forward direction
                else{ 
                    if((pos+a<=end)&&(!vis[pos+a][0])){vis[pos+a][0]=true;q.push({pos+a,0});}
                }
            }
           jumps++; 
            
        }
        return -1;
    }
};