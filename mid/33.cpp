#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

long long k, n, ans;
stack<int> S;

int main() {
    cin >> k >> n;
    while(n) S.push(n & 1), n >>= 1;
    while(!S.empty()) ans += S.top() * pow(k, S.size()-1), S.pop();
    cout << ans << endl;
    return 0;
}