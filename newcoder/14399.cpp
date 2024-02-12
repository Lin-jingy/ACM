//MLE
//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//bool prime(int x) {
//    if (x < 2)return false;
//    else {
//        int k = sqrt(x);
//        for (int i = 2; i <= k; ++i)if (x % i == 0)return false;
//    }
//    return true;
//}
//set<int>s[1000000];
//void factor(int x) {
//    int X = x;
//    A:;
//    for (int i = 2; i <= x; ++i) {
//        if (not s[x].empty()) {
//            for (auto k : s[x])s[X].insert(k);
//            break;
//        }else if (x % i == 0 and prime(i)) {
//            s[X].insert(i);
//            x /= i;
//            goto A;
//        }
//    }
//    for (auto i : s[X]) {
//        cout << i << ' ';
//    }
//    cout << '\n';
//}
//signed main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        int x; cin >> x;
//        if (prime(x)) {
//            cout << "isprime\n";
//            cout << x << '\n';
//        }
//        else {
//            cout << "noprime\n";
//            factor(x);
//        }
//
//
//    }
//    return 0;
//}




// TLE
//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//set<int>s;
//bool prime(int x) {
//    int flag = 1;
//    int k = sqrt(x);
//    for (int i = 2; i <= x / 2; ++i) {
//        if (i > k and flag)return 1;
//        if (x % i == 0) {
//            flag = 0;
//            if (prime(i))s.insert(i);
//        }
//    }
//    return flag;
//}
//signed main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        s.clear();
//        int x; cin >> x;
//        if (prime(x)) {
//            cout << "isprime\n";
//            cout << x << '\n';
//        }
//        else {
//            cout << "noprime\n";
//            for (auto i : s) {
//                cout << i << ' ';
//            }
//            cout << '\n';
//        }
//    }
//    return 0;
//}



#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        bool flag = true;
        vector<int> ans;
        int n = sqrt(x);
        for (int i = 2; i <= n; ++i) {
            if (x % i == 0) {
                flag = false;
                ans.push_back(i);
                while (x % i == 0)
                    x /= i;
            }
            if (x == 1)
                break;
        }
        if (flag) {
            cout << "isprime" << endl << x << endl;
        }
        else {
            cout << "noprime" << endl;
            for (int i = 0; i < ans.size() - 1; ++i) {
                cout << ans[i] << " ";
            }
            cout << ans.back();
            if (x != 1)
                cout << " " << x;
            cout << endl;
        }
    }
    return 0;
}