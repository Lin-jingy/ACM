#include <bits/stdc++.h>
using namespace std;
int a[50005],c[50005];
int main(){

    for(int I = 1; I <= 10; ++I) {
        freopen(std::format("C:/Users/123/Desktop/programming/VScode/ACM/data/12/data/{}.in", I).c_str(), "r", stdin);
        freopen(std::format("C:/Users/123/Desktop/programming/VScode/ACM/data/12/data/{}.out", I).c_str(), "w", stdout);

        int n = 0,k = 0,r=2,ma = 0,ans = 0;
        memset(a, 0, sizeof(a));
        memset(c, 0, sizeof(c));

        scanf("%d %d",&n,&k);
        a[n+1]=2100000000;//立个哨兵，防止r"跑丢"... 
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for(int i=1;i<=n;++i){
            while(a[r]<=a[i]+k)r++;//可以往右就尽量往右，因为我们只需要最长的。 
            c[r]=max(r-i,c[r]);
            ma=max(ma,c[i]);//记录第i颗钻石（不包括i）前可以摆最多的钻石。即第一个架子上的钻石。 
            ans=max(ans,ma+r-i);//为什么是'r-i'而不是'c[r]'? 因为要防区间重叠.qwq
        }
        std::cout << ans << std::endl;
    

        fclose(stdin);
        fclose(stdout);

        std::clog << I << std::endl;

    
    }
    return 0;
}