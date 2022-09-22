class Solution {
public:
    int clumsy(int n) {
       int ans=0;
        int add=0;
        if(n<=2){return n;}
        if(n==3){return 6;}
        vector<int>store;
        while(n>=4){
            int t=n*(n-1)/(n-2);
            store.emplace_back(t);
            add+=(n-3);
            n-=4;
        }
        if(n==3){
            ans-=n*(n-1)/(n-2);
        }
        else if(n==2){
            ans-=n*(n-1);
        }else if(n==1){
            ans-=n;
        }
        ans+=store[0];
        for(int i=1;i<store.size();i++){
            ans-=store[i];
        }
        return ans+add;
    }
};