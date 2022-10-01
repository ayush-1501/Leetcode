class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
         vector<int>st;
        for(string i:bank){
            int count=0;
            for(int j=0;j<i.size();j++){
                if(i[j]=='1'){
                    count++;
                }
            }
            if(count!=0)st.emplace_back(count);
        }
        // for(int i:st){
        //     cout<<i<<" ";
        // }
        if(st.size()<=1){return 0;}
        int ans=0;
        for(int i=0;i<st.size()-1;i++){
            ans+=st[i]*st[i+1];
            //cout<<st[i]*st[i+1]<<"\n";
        }
        return ans;
    }
};