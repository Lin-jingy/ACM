#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int, int>;

inline int read(){
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}

bool isprime(int x){
    for(int i = 2; i * i <= x; ++ i){
        if(x % i == 0)return false;
    }
    return true;
}

int p[1005][1005];

void solve(){
    int n, m;
    cin >> n >> m;
    if(!isprime(n)){
        int flag = 1;
        for(int i = 1; i <= m; ++ i){
            for(int j = 1; j <= n; ++ j)
                p[j][i] = flag++; 
        }
        for(int i = 1; i <= n; ++ i){
            for(int j = 1; j <= m; ++ j){
                cout << p[i][j] << ' ';
            }
            cout << '\n';
        }
    }else if(!isprime(m)){
        int flag = 1;
        for(int i = 1; i <= n; ++ i){
            for(int j = 1; j <= m; ++ j)
                cout << flag++ << ' '; 
            cout << '\n';
        }
    }else{
        int a[1005];
        a[1] = 1;
        //a[n / 2 + 2] = 1 + m;
        for(int i = 2; i <= n / 2 + 1; ++ i)a[i] = a[i - 1] + 2 * m;
        for(int i = n / 2 + 3; i <= n; ++ i)a[i] = a[i - 1] + 2 * m;
        for(int i = 2; i <= n; ++ i){
            if(a[i - 1] + 2 * m < n * m)a[i] = a[i - 1] + 2 * m;
            else{
                a[i] = 1 + m;
                for(int j = i + 1; j <= n; ++ j){
                    a[j] = a[j - 1] + 2 * m;
                }
                goto A;
            }
        }
        A:;
        for(int i = 1; i <= n; ++ i){
            cout << a[i] << ' ';
            for(int j = 2; j <= m; ++ j){
                cout << a[i] + j - 1 << ' ';
            }
            cout << '\n';
        }
    }
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
