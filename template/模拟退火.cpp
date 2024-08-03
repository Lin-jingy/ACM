#include <bits/stdc++.h>

#include <random>

class simulateAnneal {
   private:
    double calc();
    double ans;  // 以平均数作为初值
    std::mt19937_64 rnd;
    std::uniform_real_distribution<double> dist;

   public:
    simulateAnneal() : rnd(time(0)), dist(0, 1) {}
    void run() {
        double T = 10000;        // 模拟次数
        while (T > 0.001) {      // 退火
                                 // 随机浮动
            double nowans;       // 现在的计算答案
            double delta;        // 答案的差
            if (nowans < ans) {  // 更优则选择
                ans = nowans;
            } else if (std::exp(-delta / T) >
                       dist(rnd)) {  // 否则以多项式概率接受
                ans = nowans;
            }
            T *= 0.997;
        }
    }
};