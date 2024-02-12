#include<iostream>
using namespace std;
int mp[200];
void solve() {

    //TLE
//    int x;
//    while(1){
//        cin>>x;
//        if(x==0)break;
//        vector<int>a;
//        for(int i=1;i<=2*x;++i)a.push_back(i);
//        for(int i=2;;++i){
//            vector<int>s=a;
//            int k=0;
//            while(s.size()>x){
//                for(vector<int>::iterator it=s.begin();it!=s.end();){
//                    ++k;
//                    if(k==i){
//                        k=0;
//                        if(*it<=x)goto A;
//                        it=s.erase(it);
//                    }else ++it;
//                }
//            }
//            cout<<i<<'\n';
//            break;
//            A:;
//        }
//    }




//TLE
//    int x;
//    for (;;) {
//        cin >> x;
//        if (x == 0) break;
//        int si = x;
//        if (mp[x]==0) {
//            for (;;) {
//                int er = 0;
//                for (int j = 0; j < x; j++) {
//                    er = (er + si - 1) % (2 * x - j);
//                    if (er < x) goto A;
//                }
//                break;
//                A:;
//                si++;
//            }
//            mp[x]=si;
//        }
//        cout << mp[x] << '\n';
//    }


    //打表  RE
    int a[50]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881,13482720,25779600,68468401,610346880};
    int n;
    for(;;){
        cin>>n;
        if(n==0)return;
        cout<<a[n]<<'\n';
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    while (t--)solve();
}

