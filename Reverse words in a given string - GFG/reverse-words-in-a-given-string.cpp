//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
        string ans;
        for(int i=0;i<s.size();i++){
            string k;
            while(i!=s.size() and s[i]!='.'){
                k+=s[i];
                i++;
            }
            reverse(begin(k),end(k));
            ans+=k+".";
        }
        ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends