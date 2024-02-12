#include<bits/stdc++.h>

using namespace std;

int main(){
    int mp[100005], n, op, x, y, sum, flag = 0, i;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &op);
        if(op == 1){
            scanf("%d", &mp[flag++]);
        }else if(op == 2){
            scanf("%d", &x);
            for(i = 0; i < flag; ++i)if(mp[i] == x){
                mp[i] = 0;
                break;
            }
        }else{
            scanf("%d%d", &x, &y);
            sum = 0;
            for(i = 0; i < flag; ++i){
                if(mp[i] > 0 and (x ^ mp[i]) < y) sum++;
            }
            printf("%d\n", sum);
        }
    }
    return 0;
}
