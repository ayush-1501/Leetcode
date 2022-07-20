class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        deque<int>a(students.begin(),students.end());
        deque<int>b(sandwiches.begin(),sandwiches.end());
        int counter=0;
        while(!a.empty()){
            int st=a.front();a.pop_front();
            int sa=b.front();
            if(st==sa){b.pop_front();counter=0;continue;}
            else{
                a.push_back(st);
                b.push_back(sa);
                counter++;
            }
            if(counter==a.size()){break;}
        }
        return a.size();
    }
};