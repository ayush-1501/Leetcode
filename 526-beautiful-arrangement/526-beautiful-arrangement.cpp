class Solution {
public:
    typedef long long ll;
    ll res = 0;
    void func(int pos,int used, int& n) {
        if (pos==n+1) {
            ++res;
            return;
        }
        for (int i=1;i<=n;++i) {
            if (!((pos%i && i%pos)||(used&(1<<i)))) {
                func(pos+1,used^(1<<i), n);
            }
        }
    }
    int countArrangement(int n) {
        func(1, 0, n);
        return res;
    }
};