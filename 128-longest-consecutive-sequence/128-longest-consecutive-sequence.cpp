class Solution {
public:
    // find set function with path compression technique
    int find_set(int x,vector<pair<int,int>>& parent)
    {
        if(parent[x].first==x)
            return x;
        return parent[x].first = find_set(parent[x].first,parent);
    }
 
    // union set function with rank compression technique
    void union_set(int x,int y,vector<pair<int,int>>& parent,vector<int>& sz)
    {
        int xroot = find_set(x,parent);
        int yroot = find_set(y,parent);
 
        if(xroot==yroot)
            return;
        if(parent[xroot].second>parent[yroot].second){
            parent[yroot].first = xroot;
            sz[xroot]+=sz[yroot]; 
        }
        else if(parent[yroot].second>parent[xroot].second){
            parent[xroot].first = yroot;
            sz[yroot]+=sz[xroot];
        }
        else{
            parent[xroot].second++;
            parent[yroot].first = xroot;
            sz[xroot]+=sz[yroot];
        }
    }
 
    int longestConsecutive(vector<int>& nums) {
        // base case
        if(nums.empty())
            return 0;
        int ind = 0; // unique key
        unordered_map<int,int> index; // assign every unique element a unique key
        for(int i=0;i<nums.size();i++){
            if(!index.count(nums[i])){
                index[nums[i]] = ind++;
            }
        }
 
        // {parent,rank}
        vector<pair<int,int>> parent; // size exactly equal to ind+1 unique keys
        // size of connected component
        vector<int> sz(ind+1,1); // storing the size of connected components
 
        // assigning default values for union-find and path compression technique
        for(int i=0;i<ind;i++){
            parent.push_back({i,0});
        }
 
        for(auto it:nums){
            // if it exists, then union set
            if(index.count(it+1))
                union_set(index[it],index[it+1],parent,sz);
            if(index.count(it-1))
                union_set(index[it],index[it-1],parent,sz);
        }
 
        // find the maximum size of connected component
        return *max_element(sz.begin(),sz.end());
    }
};