#include<bits/stdc++.h>
long long n,x,sum=INT_MIN,answer=0,i;
signed main(){
    for(std::cin>>n,i=0;i<n;++i){
        std::cin>>x;
        sum+=x;
        if(sum<0)sum=0;
        answer=std::max(answer,sum);
    }
    std::cout<<answer;
    return 0;
}