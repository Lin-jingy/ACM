#include <iostream>
#include <queue>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    std::cin >> n;
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    while (n--) {
        int op, x;
        std::cin >> op;
        if (op == 1) {
            std::cin >> x;
            q.push(x);
        } else if (op == 2) {
            std::cout << q.top() << '\n';
        } else {
            q.pop();
        }
    }
}