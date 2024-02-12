#include<bits/stdc++.h>

int main(){
    int n, m;
    std::cin >> n >> m;
    std::vector<int>a(n + 1), b(m + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    for(int i = 1; i <= m; ++i) std::cin >> b[i];
    int sk;
    std::cin >> sk;

    std::vector<std::vector<int>> p(n + 1, std::vector<int>(m + 1));

    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) p[i][j] = a[i] * b[j];

    std::vector<std::vector<int>>pre(m + 1, std::vector<int>(n + 1));
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            pre[i][j] = pre[i][j - 1] + p[j][i];
        }
    }

    int ans = 0;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            for(int k = i; k <= n; ++k){
                int sum = 0;
                for(int l = j; l <= m; ++l){
                    sum += pre[l][k] - pre[l][i - 1];
                    if(sum <= sk) ans = std::max(ans, (k - i + 1) * (l - j + 1));
                    else break;
                }
            }
        }
    }

    std::cout << ans << '\n';

    return 0;
}