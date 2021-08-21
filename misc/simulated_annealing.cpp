#include <bits/stdc++.h>

using namespace std;

double ans;

double calc() {
    double res = 0;
    // TODO: 计算当前方案的值
    ans = max(ans, res);  // 更新全局答案
    return res;
}

void simulate_anneal() {
    for (double t = 1e6; t > 1e-6; t *= 0.95) {
        double x = calc();  // 原方案的值
        // TODO: 随机一个新方案
        double y = calc();  // 新方案的值
        double delta = y - x;
        // 新方案更好，则必选新方案；否则以一定概率选新方案 
        if (exp(delta / t) > (double)rand() / RAND_MAX) {
            // TODO: 换成新方案
        }
    }
}

int main() {
    for (int i = 0; i < 100; i++) simulate_anneal();
    while ((double)clock() / CLOCKS_PER_SEC < 0.8) simulate_anneal(); // 卡时
    return 0;
}