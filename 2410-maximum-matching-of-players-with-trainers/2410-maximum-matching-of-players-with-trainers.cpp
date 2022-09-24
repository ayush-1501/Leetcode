class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(begin(players),end(players));
        sort(begin(trainers),end(trainers));
        int count=0;
        for(int i=0;i<players.size();i++){
            for(int j=i;j<trainers.size();j++){
                if(trainers[j]>=players[i]){
                    trainers[j]=-1;
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};