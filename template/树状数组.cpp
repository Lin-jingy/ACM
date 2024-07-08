#include <bits/stdc++.h>

class BIT{
#define lowb(x) ((-x) & x)
private:int n;std::vector<int> c;std::vector<int> *a;
public:BIT(int N,std::vector<int>*A):n(N),c(n+1),a(A){
        for(int i=1;i<=n;i++)for(int j=i;j<=n;j+=lowb(j))c[j]+=(*a)[i];}
    void add(int i, int z){ (*a)[i]+=z;for(;i<=n;i+=lowb(i))c[i]+=z; }
    int pre(int i){ int sum=0;for (;i>0;i-=lowb(i))sum+=c[i];return sum; }
    int sum(int i, int j){ return pre(j) - pre(i - 1); }
#undef lowb
};
