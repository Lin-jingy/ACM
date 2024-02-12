#include<bits/stdc++.h>

const int N = 1e6 + 5;
int f[N];
int n, a, b;

int sg(int x){
    if(f[x] != -1) return f[x];
    std::unordered_set<int> st;
    for(int i = a; i <= b; ++i) st.insert(sg(x-i));
    for(int i = 0; ;i++){
        if(!st.count(i)) return f[x] = i;
    }
}


int main(){
    std::cin >> n >> a >> b;

    memset(f,-1,sizeof(f));
    int ans = 0;
    for(int i = 0, x; i < n; ++i) ans ^= sg(x);
    
    if(ans) std::cout << "C\n";
    else std::cout << "Y\n";

    return 0;
}