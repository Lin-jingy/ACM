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

const int N = 2e5 + 5;
int a[N], b[N], p[N];
int sum, m[N];

void mergeSort(int l, int r, int *a){
    if(r - l <= 1){
        if(a[l] > a[r])++sum, swap(a[l], a[r]);
        return;
    }
    int mid = l + r >> 1;
    mergeSort(l, mid, a);
    mergeSort(mid + 1, r, a);
    for(int i = l; i <= r; ++i)p[i] = a[i];
    int i = l, j = mid + 1, flag = l;
    while(i <= mid and j <= r){
        if(p[i] > p[j]) {
            sum += mid - i + 1;
            a[flag++] = p[j++];
        }else a[flag++] = p[i++];
    }
    while(i <= mid) a[flag++] = p[i++];
    while(j <= r) a[flag++] = p[j++];
}

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i], p[a[i]]++;
    for(int i = 1; i <= n; ++i) cin >> b[i], p[b[i]]--;
    for(int i = 1; i <= n; ++i) if(p[i] != 0){
        no;
        return;
    }
    for(int i = 1; i <= n; ++i){
        p[a[i]]++;
        if(p[a[i]] >= 2){
            yes;
            return;
        }
    }
    mergeSort(1, n, a);
    int k = sum;
    sum = 0;
    mergeSort(1, n, b);
    if(sum % 2 == k % 2)yes;
    else no;
    
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    //cin >> _;
    while(_--)solve();
    return 0;
}
