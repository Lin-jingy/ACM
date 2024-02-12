#include<bits/stdc++.h>

int a[205];
int p[10], xp[10];

int main(){
    int T;
    std::cin >> T;
    while(T--){
        int n;
        std::cin >> n;
        for(int i = 1; i <= 9; ++i) p[i] = xp[i] = 0;
        for(int i = 1; i <= n; ++i) std::cin >> a[i], p[a[i]]++;

        std::cout << "- 0" << std::endl;//1

        for(int i = 1; i <= n; ++i) std::cin >> a[i], xp[a[i]]++;
        
        int flag;
        for(int i = 1; i <= 9; ++i) if(xp[i] > p[i]) {
            flag = i;
            goto B;
        }

        std::cout << "- 0" << std::endl;//2
        for(int i = 1; i <= 10; ++i) xp[i] = 0;
        for(int i = 1; i <= n; ++i) std::cin >> a[i], xp[a[i]]++;
        for(int i = 1; i <= 9; ++i) if(xp[i] > p[i]) {
            flag = i;
            goto B;
        }
        std::cout << "- 0" << std::endl;//3
        for(int i = 1; i <= 10; ++i) xp[i] = 0;
        for(int i = 1; i <= n; ++i) std::cin >> a[i], xp[a[i]]++;
        for(int i = 1; i <= 9; ++i) if(xp[i] > p[i]) flag = i;
        B:;
        int sum(0);
        for(int i = 1; i <= n; ++i) if(a[i] == flag) ++sum;
        std::cout << "- ";
        std::cout << n - sum << ' ';
        for(int i = 1; i <= n; ++i) if(a[i] != flag) std::cout << i << ' ';
        std::cout << std::endl;//4
            
        int k = 0;
        for(int i = 1; i <= sum; ++i) std::cin >> a[i]; 
        for(int i = 1; i <= sum; ++i) if(a[i] != flag){
            std::cout << "! " << i << std::endl;
            goto A;
        }

        std::cout << "- 0" << std::endl;//5
        for(int i = 1; i <= sum; ++i) std::cin >> a[i];
        for(int i = 1; i <= sum; ++i) if(a[i] != flag){
            std::cout << "! " << i << std::endl;
            goto A;
        }
        A:;
    }
}