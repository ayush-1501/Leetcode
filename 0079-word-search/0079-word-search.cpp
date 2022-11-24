class Solution {
public:
   bool check(vector<vector<char>>& b,string &t,int r,int c,int in){
        if(r<0 or r>=b.size() or c<0 or c>=b[0].size() or b[r][c]!=t[in]){
            return false;
        }
        if(in==t.size()-1)
            return true;
       if(in>=t.size()){return false;}
        
       b[r][c]='$';
       bool ans= check(b,t,r+1,c,in+1)or
        check(b,t,r-1,c,in+1)or
        check(b,t,r,c-1,in+1)or
        check(b,t,r,c+1,in+1);
       
       
       b[r][c]=t[in];
        return ans;
    }
    bool exist(vector<vector<char>>& b, string w) {
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[0].size();j++){
               if(b[i][j]==w[0]){
                   if(check(b,w,i,j,0)){
                       return true;
                   }
               }
            }
        }
        return false;
    }
};