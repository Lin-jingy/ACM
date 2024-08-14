#include <bits/stdc++.h>

class BIT{
#define lowb(x) ((-x) & x)
private:
    int n;
    std::vector<int> c;
public:
    BIT() = default;
    BIT(int N):n(N), c(N+1){}
    void add(int i, int z){ 
        for(; i <= n; i += lowb(i)) c[i] += z; 
    }
    int pre(int i){ 
        int sum = 0;
        for (; i > 0; i -= lowb(i)) sum += c[i];
        return sum; 
    }
    int sum(int i, int j){ 
        return pre(j) - pre(i - 1); 
    }
#undef lowb
};


class BIT1{
#define lowb(x) ((-x) & x)
private:
    int n;
    std::vector<int> c, *a;
public:
    BIT1(int N, std::vector<int>*A):n(N), c(N+1), a(A){
        for(int i = 1; i <= n; i++)
            for(int j = i; j <= n; j += lowb(j))
                c[j] += a->at(i);
    }
    void add(int i, int z){ 
        a->at(i) += z;
        for(; i <= n; i += lowb(i)) c[i] += z; 
    }
    int pre(int i){ 
        int sum = 0;
        for (; i > 0; i -= lowb(i)) sum += c[i];
        return sum; 
    }
    int sum(int i, int j){ 
        return pre(j) - pre(i - 1); 
    }
#undef lowb
};
