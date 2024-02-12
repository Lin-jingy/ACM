#include<iostream>
#include<set>
#include<string>
#include<algorithm>
#define int long long
using namespace std;
string answer[100000];
int flag = 0;
set<string>std1;
void fact(int k, int n, string a) {
    string a1 = a;
    int len = std1.size();
    if (k == n ) {
        std1.insert(a);
        if (len < std1.size()) {
            answer[flag]=a1;
            flag++;
        }
    }else {
        for (int i = 1; i <= n; ++i) {
            string ab=a+to_string(i);
            int kk=0;
            sort(ab.begin(), ab.end());
            for (int j = 0; j < ab.size()-1; ++j) {
                if (ab[j] == ab[j + 1]) { kk++; break; }
            }   
            if (kk == 0) 
                fact(k + 1, n, a + to_string(i));
        }
    }

}
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        fact(1, n, to_string(i));
    }
    for (int i = 0; i < flag; ++i) {
         for (int j = 0; j < answer[i].size(); ++j) {
                printf("%5.c",answer[i][j]);
            }
            printf("\n");
    }
    return 0;
}