//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	const int mod=1e9+7;
	int solve(int arr[],int idx,int n,int sum,int s,vector<vector<int>>&dp){
	    if(s>sum)return 0;
	    if(idx==n){
	        if(sum==s)return 1;
	        else return 0;
	    }
	    if(dp[idx][s]!=-1)return dp[idx][s];
	    //take
	    s+=arr[idx];
	    int take=solve(arr,idx+1,n,sum,s,dp);
	    s-=arr[idx];
	    
	    //not take
	    int not_take=solve(arr,idx+1,n,sum,s,dp);
	    return dp[idx][s]=(take+not_take)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int s=0;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(arr,0,n,sum,s,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends