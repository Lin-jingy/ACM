#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;cin>>n;
    string a;
    int flag=0;
    while(n--){
        cin>>a;
        if(a=="and" or a=="not" or a=="that" or a=="the" or a=="you"){
            flag=1;
        }
    }
    if(flag)cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}