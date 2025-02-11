#include <bits/stdc++.h>
void dfs(std::string a, std::string b) {
    int len = a.size();
    if (len > 0) {
        char ch = b[len - 1];
        std::cout << ch;
        int pos = a.find(ch);
        dfs(a.substr(0, pos), b.substr(0, pos));
        dfs(a.substr(pos + 1), b.substr(pos, len - pos - 1));
    }
}
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::string a, b;
    std::cin >> a >> b;
    dfs(a, b);
    return 0;
}