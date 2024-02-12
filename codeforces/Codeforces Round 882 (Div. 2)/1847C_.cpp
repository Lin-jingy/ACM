#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define inf LONG_LONG_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

const int N =( 1e5 + 10) * 31, M = 1e5 + 10;
int son[N][2],idx,arr[M], s[M],cnt[N];
void insert(int x, int val)
{
    int p = 0;
    for(int i = 30 ;i >= 0; i --)
    {
        int u = x >> i & 1;
        if(!son[p][u])son[p][u] = ++idx;
        p = son[p][u];
        cnt[p] += val;
    }
}
int query(int x)
{
    int p = 0,res = 0;
    for(int i = 30; i >= 0; i --)
    {
        int u = x >> i & 1;
        if(cnt[ son[p][!u] ] )
        {
            res += 1 << i;
            p = son[p][!u];
        }
        else p = son[p][u];
    }
    return res;
}

signed main()
{
    int t;
    cin >> t;
    while(t--){
        int n,m,res = 0;
        cin>>n;
        for(int i = 0; i < n + 5; ++i)son[i][0] = son[i][1] = arr[i] = s[i] = cnt[i] = 0;
        m = n;
        for(int i = 1; i <= n; i ++ )
        {
            int x;
            cin>>x;
            s[i] = s[i - 1] ^ x;
        }
        insert(s[0],1);

        for(int i = 1;i <= n; i ++ )
        {
        
            if(i > m )insert(s[i - m - 1], -1);
      
            res  = max(res, query(s[i]));
            insert(s[i],1);
        }
        cout<<res << '\n';
    }
    
}