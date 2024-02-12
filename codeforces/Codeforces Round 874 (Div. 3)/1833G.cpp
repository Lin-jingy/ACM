#include<bits/stdc++.h>

const int N = 2e5 + 5;

std::vector<int>ans;
std::vector<std::pair<int, int>>a[N];
std::vector<bool>vis(N);
std::vector<int>fa(N);

bool flag = true;

int dfs(int pos){
    if(flag == false) return 0;
    if(vis[pos]) return 0;
    vis[pos] = 1;
    int sum(1);
    for(auto i:a[pos]){
        if(!vis[i.first])fa[i.first] = i.second;
        sum += dfs(i.first);
    }
    if(sum == 3 and pos != 1){
        sum = 0;
        ans.push_back(fa[pos]);
    }else if(sum > 3) flag = false;
    return sum;
}

int main(){
    int T;
    std::cin >> T;
    while(T--){
        int n;
        std::cin >> n;
        ans.clear();
        flag = true;
        for(int i = 1; i <= n; ++i) a[i].clear(), vis[i] = 0, fa[i] = 0;
        for(int i = 1; i < n; ++i){
            int u, v;
            std::cin >> u >> v;
            a[u].push_back({v, i});
            a[v].push_back({u, i});
        }

        if(n % 3 != 0){
            std::cout << -1 << '\n';
            continue;
        }

        dfs(1);

        if(flag == false) std::cout << "-1\n";
        else {
            std::cout << ans.size() << '\n';
            for(auto i:ans) std::cout << i << ' ';
            std::cout << '\n';
        }
    }





}