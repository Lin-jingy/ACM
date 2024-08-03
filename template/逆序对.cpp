#include <bits/stdc++.h>

static long long Reverse_pair(std::vector<int> &a) {  // 1~n
    long long ans = 0;
    std::vector<int> c(a.size() + 1);
    auto msort = [&](auto &&self, int b, int e) {
        if (b == e) return;
        int mid = (b + e) / 2, i = b, j = mid + 1, k = b;
        self(self, b, mid);
        self(self, mid + 1, e);
        while (i <= mid && j <= e)
            if (a[i] <= a[j]) c[k++] = a[i++];
            else
                c[k++] = a[j++], ans += mid - i + 1;  // 统计答案
        while (i <= mid) c[k++] = a[i++];
        while (j <= e) c[k++] = a[j++];
        memcpy(&a[b], &c[b], sizeof(int) * (e - b + 1));
    };
    msort(msort, 1, a.size() - 1);
    return ans;
}