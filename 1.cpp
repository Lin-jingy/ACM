#include <algorithm>
#include <iostream>
#include <vector>

std::string a;
using Pii = std::pair<int, int>;

int find(int begin) {
    int cnt = 0;
    for (int i = begin; i < a.size(); ++i) {
        if (a[i] == '(') cnt++;
        else cnt--;
        if (cnt < 0) return -1;
        if (i != begin and cnt == 0) return i;
    }
    return -1;
}

void dfs(int l, int r) {
    if (l > r) return;
    std::vector<Pii> v;
    for (int i = l; i <= r; ++i) {
        auto it = find(i);
        if (it != -1) {
            dfs(i + 1, it - 1);
            v.emplace_back(i, it);
            i = it;
        } else {
            if (v.empty()) continue;
            if (v.size() == 1) {
                v.clear();
                continue;
            }
            int begin = v.front().first;
            std::string ca = a;
            std::sort(v.begin(), v.end(), [](Pii a, Pii b) {
                return a.second - a.first > b.second - b.first;
            });
            for (auto it : v) {
                int len = it.second - it.first + 1;
                a.replace(begin, len, ca.substr(it.first, len));
                begin += len;
            }
            v.clear();
        }
    }
    if (v.empty()) return;
    int begin = v.front().first;
    std::string ca = a;
    std::sort(v.begin(), v.end(), [](Pii a, Pii b) {
        return a.second - a.first > b.second - b.first;
    });
    for (auto it : v) {
        int len = it.second - it.first + 1;
        a.replace(begin, len, ca.substr(it.first, len));
        begin += len;
    }
}

int main() {
    std::cin >> a;
    dfs(0, a.size() - 1);
    std::cout << a << '\n';
    return 0;
}
