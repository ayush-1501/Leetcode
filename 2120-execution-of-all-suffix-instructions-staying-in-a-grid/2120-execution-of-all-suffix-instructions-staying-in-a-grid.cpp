class Solution {
public:
   	int dfs(int i, int j, int n, int l, string &s){
		if(i<0 or j<0 or i>=n or j>=n or l>=s.size())
			return 0;
		if(i-1>=0 and s[l]=='U')
			return 1+dfs(i-1,j,n,l+1,s);
		if(i+1<n and s[l]=='D')
			return 1+dfs(i+1,j,n,l+1,s);
		if(j-1>=0 and s[l]=='L')
			return 1+dfs(i,j-1,n,l+1,s);
		if(j+1<n and s[l]=='R')
			return 1+dfs(i,j+1,n,l+1,s);
		return 0;
	}

	vector<int> executeInstructions(int n, vector<int>& start, string s) {
		vector<int> ans;
		for(int i=0;i<s.size();i++){
			ans.emplace_back(dfs(start[0],start[1],n,i,s));
		}
		return ans;
	}

};