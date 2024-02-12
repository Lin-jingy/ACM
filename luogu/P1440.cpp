#include<iostream>
#include<deque>
using namespace std;
deque<pair<int, int>>q;
signed main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int x;
    scanf("%d", &x);
    q.push_back(make_pair(x, 1));
    printf("0\n");
    scanf("%d", &x);
    for (int i = 2; i <= n; ++i) {
        while (!q.empty() && q.front().second < i - m) { q.pop_front(); }//判断数据是否过期
        printf("%d\n",q.front().first);
        while (!q.empty() && x < q.back().first) { q.pop_back(); }//维护升序
        q.push_back(make_pair(x, i));//存入下一个值
        scanf("%d", &x);
    }
    return 0;
}