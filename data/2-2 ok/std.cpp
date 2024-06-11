#include<bits/stdc++.h>
using namespace std;

inline int read(){int s=0,w=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();return s*w;}

struct po
{
	int w,s;
};
po a[50001];

bool cmp(po a,po b){
	return a.w + a.s < b.w + b.s;
}

int main(int argc, char const *argv[])
{

    for(int I = 1; I <= 10; ++I) {
        freopen(std::format("C:/Users/123/Desktop/programming/VScode/ACM/data/2-1/data/{}.in", I).c_str(), "r", stdin);
        freopen(std::format("C:/Users/123/Desktop/programming/VScode/ACM/data/2-1/data/{}.out", I).c_str(), "w", stdout);

        memset(a, 0, sizeof(a));

        int n;
        cin>>n;
        for(int i = 1;i <= n;++i){
            a[i].w = read();
            a[i].s = read();
        }
        sort(a + 1,a + 1 + n,cmp);//贪心排序
        int tot = 0,ans = -99999999;//一个数减另一个数,不排除负数的可能,ans要弄负值
        for(int i = 1;i <= n;++i){
            ans = max(ans,tot - a[i].s);
            tot += a[i].w;
        }
        cout<<ans<<endl;
        
        fclose(stdin);
        fclose(stdout);

        std::clog << I << std::endl;
    }

    return 0;
	
}