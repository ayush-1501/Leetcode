class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int>save(rocks.size(),0);
        for(int i=0;i<rocks.size();i++){
            save[i]=capacity[i]-rocks[i];
        }
        sort(save.begin(),save.end());
        int t=additionalRocks,c=0;
        while(1){
            if(save[c]==0){}
            else t-=save[c];
            if(t<0){break;}
            c++;
            if(c==save.size()){break;}
        }
        return c;
    }
};