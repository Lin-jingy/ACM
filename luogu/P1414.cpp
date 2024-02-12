#include<bits/stdc++.h>

const int N = 1e6 + 5;

int t[N];
int ans[10005];

int main(){
    int n;
    std::cin >> n;
    for(int i = 1, x; i <= n; i++) std::cin >> x, t[x]++;
    for(int i = 1; i < N;i++){
        int sum = 0;
        for(int j = 1; i * j < N; j++) sum += t[i * j];
        ans[sum] = i;
    }
    for(int i = n - 1; i >= 1; i--) ans[i] = std::max(ans[i], ans[i+1]);
    for(int i = 1; i <= n; i++) std::cout << ans[i] << '\n';
    return 0;
} 