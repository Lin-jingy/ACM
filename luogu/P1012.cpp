#include<bits/stdc++.h>
#define int long long
using namespace std;
struct words{
    string word;
    int len;
}a[21];
bool fact(words a,words b){
    return a.word+b.word>b.word+a.word;
}
signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i].word;
        a[i].len=a[i].word.size();
    }
    sort(a,a+n,fact);
    string x;
    for(int i=0;i<n;++i){
        x.append(a[i].word);

    }
    cout<<x;
    return 0;
}