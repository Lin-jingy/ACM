#define _ijps 0
#define _CRT_SECURE_NO_DEPRECATE 
#pragma comment(linker, "/STACK:667772160")
#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <algorithm>
#include <string>
#include <list>
#include <bits/stdc++.h>
using namespace std;

#define name "twosquares"
typedef unsigned long long ull;
typedef long long ll;
#define mk make_pair
#define forn(i, n) for(ll i = 0; i < (ll)n; i++)
#define fornn(i, q, n) for(ll i = (ll)q; i < (ll)n; i++)
#define times clock() * 1.0 / CLOCKS_PER_SEC

struct __isoff{
    __isoff(){
        if (_ijps)
            freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);//, freopen("test.txt", "w", stderr);
        //else freopen(name".in", "r", stdin), freopen(name".out", "w", stdout);
        ios_base::sync_with_stdio(0);
        srand(time(0));
    }
    ~__isoff(){
        //if(_ijps) cout<<times<<'\n';
    }
} __osafwf;
const ull p1 = 131797;
const ull p2 = 435493969;
const double eps = 1e-7;
const double pi = acos(-1.0);

const ll inf = 1e18 + 7;
const int infi = 1e9 + 7;
const ll dd = 2e5 + 7;
const ll mod = 1e9 + 7;

ll fac[1000];
int n, k, c;
ll sd;
vector<ll> T;
vector<ll> sum;
ll res = 0;

map<ll, int> D[30];

void dfs(int v, int t, ll sum){
    if(sum > sd || t > k)
        return;
    if(v == n / 2){
        forn(j, k - t + 1)
            D[j][sum]++;
        return;
    }
    if(T[v] <= c)
        dfs(v + 1, t + 1, sum + fac[T[v]]);
    
    if(rand() % 2){
        dfs(v + 1, t, sum + T[v]);
        dfs(v + 1, t, sum);
    }
    else{
        dfs(v + 1, t, sum);
        dfs(v + 1, t, sum + T[v]);
    }
}

void dfs2(int v, int t, ll sum){
    if(sum > sd || t > k)
        return;
    if(v == n){
        if(D[t].count(sd - sum))
            res += D[t][sd - sum];
        return;
    }
    if(T[v] <= c)
        dfs2(v + 1, t + 1, sum + fac[T[v]]);
    
    if(rand() % 2){
        dfs2(v + 1, t, sum + T[v]);
        dfs2(v + 1, t, sum);
    }
    else{
        dfs2(v + 1, t, sum);
        dfs2(v + 1, t, sum + T[v]);
    }
}

void solve(int dataID) {
    std::string address1 = std::format("C:/Users/123/Desktop/programming/VScode/ACM/data/14/data/{}.in", dataID);
    std::string address2 = std::format("C:/Users/123/Desktop/programming/VScode/ACM/data/14/data/{}.out", dataID);
    freopen(address1.data(), "r", stdin);
    freopen(address2.data(), "w", stdout);
    fac[0] = 1;
    fornn(i, 1, 1000){
        fac[i] = fac[i - 1] * i;
        c = i;
        if(fac[i] > 1e16)
            break;
    }
    cin >> n >> k >> sd;
    T.resize(n);
    forn(i, n){
        cin >> T[i];
    }
    sort(T.begin(), T.end());
    dfs(0, 0, 0);
    dfs2(n / 2, 0, 0);
    cout << res << std::endl;
    fclose(stdin);
    fclose(stdout);
}

int main(){
    
    for(int i = 1; i <= 102; ++i) {
        memset(fac, 0, sizeof(fac));
        n = k = c = 0;
        sd = 0;
        T.clear();
        sum.clear();
        res = 0;



        solve(i);
        std::clog << i << std::endl;
    }
}