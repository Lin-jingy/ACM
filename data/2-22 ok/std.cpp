#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios::sync_with_stdio(false);

    for(int I = 1; I <= 20; ++I) {
        freopen(std::format("C:/Users/123/Desktop/programming/VScode/ACM/data/2-22/data/{}.in", I).c_str(),"r",stdin);
        freopen(std::format("C:/Users/123/Desktop/programming/VScode/ACM/data/2-22/data/{}.out", I).c_str(),"w",stdout);



        int n,m,k,c=0; cin>>n>>m>>k;
        vector<int> a(n),b;
        for(auto &i:a)cin>>i;
        for(int i=0;i<m;i++)b.emplace_back(a[i]);
        sort(b.begin(),b.end());
        for(int i=0;i<k;i++)c+=b[i]; // 先处理出第一个答案
        cout<<c<<' ';
        for(int i=1;i<=n-m;i++){
            auto l=lower_bound(b.begin(),b.end(),a[i-1]); // 查询需要删除的数的 rank
            if(l-b.begin()<k)c+=b[k]-*l; b.erase(l); // 有影响
            b.insert(upper_bound(b.begin(),b.end(),a[i+m-1]),a[i+m-1]); // 插入
            auto r=lower_bound(b.begin(),b.end(),a[i+m-1]); // 插入后查询 rank
            if(r-b.begin()<k)c+=a[i+m-1]-b[k]; // 有影响
            cout<<c<<' ';
        }
        cout<<endl;

        fclose(stdin);
        fclose(stdout);
        std::clog << I << std::endl;
    }


    return 0;
}