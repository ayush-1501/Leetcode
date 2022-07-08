// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    int knap(int wt[],int val[],int ind, int w,vector<vector<int>>&dp){
        if(ind==0){
            if(wt[0]<=w)return val[0];
            else return 0;
        }
        
        
        if(dp[ind][w]!=-1)return dp[ind][w];
        
        int notTake=0+knap(wt,val,ind-1,w,dp);
        
        int take=INT_MIN;
        if(wt[ind]<=w){
            take=val[ind]+knap(wt,val,ind-1,w-wt[ind],dp);
        }
        
        return dp[ind][w]=max(notTake,take);
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n,vector<int>(W+1,-1));
       return knap(wt,val,n-1,W,dp);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends