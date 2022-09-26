 vector<int>alpha(27);
class dsu{
public:
   dsu(){
      for(int i=0;i<26;i++)alpha[i]=i;
   }
   int find_par(int i){
      if(i==alpha[i])return i;
      return alpha[i]=find_par(alpha[i]);
   }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        dsu a;
        for(string i:equations){
            char num1=i[0]-'a';
            char num2=i[3]-'a';
           //cout<<a.find_par(num1)<<" "<<a.find_par(num2)<<"\n";
            if(i.substr(1,2)=="=="){
                alpha[a.find_par(num2)]=alpha[a.find_par(num1)];
            }
           // cout<<a.find_par(num1)<<" "<<a.find_par(num2)<<"\n";
        }
        for(string i:equations){
            char num1=i[0]-'a';
            char num2=i[3]-'a';
            if(i.substr(1,2)=="!="){
                if(a.find_par(num1)==a.find_par(num2)){
                    return false;
                }
            }
        }
        return true;
    }
};