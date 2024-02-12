#include<bits/stdc++.h>

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    std::cin >> n;

    std::vector<int>a(n + 1), du(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i], du[a[i]]++;

    std::queue<int>q;
    for(int i = 1; i <= n; ++i) if(du[i] == 0) q.push(i);
    int ans = n;
    while(!q.empty()){
        int f = q.front();
        q.pop();
        ans--;
        du[a[f]]--;
        if(du[a[f]] == 0) q.push(a[f]);
    }

    std::cout << ans << '\n';
    return 0;
}