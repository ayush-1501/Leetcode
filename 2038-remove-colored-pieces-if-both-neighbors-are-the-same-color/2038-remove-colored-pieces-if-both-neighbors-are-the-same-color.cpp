class Solution {
public:
    bool winnerOfGame(string colors) {
        int Acolor=0,Bcolor=0;
        for(int i=1;i<colors.size()-1;i++){
            if(colors[i]=='A' and colors[i-1]=='A' and colors[i+1]=='A'){
                Acolor++;
            }
            if(colors[i]=='B' and colors[i-1]=='B' and colors[i+1]=='B'){
                Bcolor++;
            }
        }
        if(Acolor==0){return false;}
        if(Acolor-Bcolor>0){
            return true;
        }else{
            return false;
        }
    }
};