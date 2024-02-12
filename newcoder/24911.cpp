#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
#define int long long
int a[10][10];
bool line[10][10], column[10][10], block[10][10];
int flag = 0;
int pd(int x, int y) {
    if ((x == 1 or x == 2 or x == 3) and (y == 1 or y == 2 or y == 3))return 1;
    if ((x == 4 or x == 5 or x == 6) and (y == 1 or y == 2 or y == 3))return 2;
    if ((x == 7 or x == 8 or x == 9) and (y == 1 or y == 2 or y == 3))return 3;
    if ((x == 1 or x == 2 or x == 3) and (y == 4 or y == 5 or y == 6))return 4;
    if ((x == 4 or x == 5 or x == 6) and (y == 4 or y == 5 or y == 6))return 5;
    if ((x == 7 or x == 8 or x == 9) and (y == 4 or y == 5 or y == 6))return 6;
    if ((x == 1 or x == 2 or x == 3) and (y == 7 or y == 8 or y == 9))return 7;
    if ((x == 4 or x == 5 or x == 6) and (y == 7 or y == 8 or y == 9))return 8;
    if ((x == 7 or x == 8 or x == 9) and (y == 7 or y == 8 or y == 9))return 9;
    return 0;
}
void dfs(int x, int y) {
    if (flag)return;
    if (a[x][y] == 0) {
        for (int i = 1; i <= 9; ++i) {
            if (!line[x][i] and !column[y][i] and !block[pd(x, y)][i]) {
                line[x][i] = true;
                column[y][i] = true; 
                block[pd(x, y)][i] = true;
                a[x][y] = i;
                if (y != 9)dfs(x, y+1);
                else if (y == 9 and x != 9)dfs(x+1,1);
                else if (x == 9 and y == 9) {
                    for (int i = 1; i <= 9; ++i) {
                        for (int j = 1; j <= 8; ++j) {
                            cout << a[i][j]<<' ';
                        }
                        cout <<a[i][9]<<'\n';
                    }
                    flag = 1;
                }
                line[x][i] = false;
                column[y][i] = false;
                block[pd(x, y)][i] = false;
                a[x][y] = 0;
            }
        }
    }
    else {
        if (y != 9)dfs(x, y+1);
        else if(x==9 and y==9){
            for (int i = 1; i <= 9; ++i) {
                for (int j = 1; j < 9; ++j) {
                    cout << a[i][j]<<' ';
                }
                cout <<a[i][9]<<'\n';
            }
            flag = 1;
        }else dfs(x+1, 1);
    }
    if (flag)return;
    return;
}
signed main() {
    for (int i = 1; i <= 9; ++i)for (int j = 1; j <= 9; ++j) {
        cin >> a[i][j];
        line[i][a[i][j]] = true;
        column[j][a[i][j]] = true;
        block[pd(i, j)][a[i][j]] = true;
    }
    dfs(1, 1);
    return 0;
}