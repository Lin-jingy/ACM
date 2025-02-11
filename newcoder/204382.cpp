#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int 二叉树节点数量
     * @param pre intvector 前序序列
     * @param suf intvector 后序序列
     * @return intvector
     */
    vector<int> solve(int n, vector<int>& pre, vector<int>& suf) {
        // write code here
        vector<int> ans;
        vector<int> sufPos(n + 1);
        for (int i = 0; i < n; ++i) {
            sufPos[suf[i]] = i;
        }

        auto dfs = [&](auto self, int l1, int r1, int l2, int r2) -> void {
            if (l1 > r1 || l2 > r2) return;
            if (l1 == r1) {
                ans.push_back(pre[l1]);
                return;
            }
            int root = pre[l1];
            int lroot = pre[l1 + 1];
            int pos = sufPos[lroot];
            int lenL = pos - l2 + 1;

            self(self, l1 + 1, l1 + lenL, l2, l2 + lenL - 1);
            ans.push_back(root);
            self(self, l1 + lenL + 1, r1, l2 + lenL, r2 - 1);
        };

        dfs(dfs, 0, n - 1, 0, n - 1);
        return ans;
    }
};