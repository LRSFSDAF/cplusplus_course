#include <iostream>
using namespace std;

// 函数声明：计算 n 阶勒让德多项式在 x 处的值
double P(int n, double x);

int main() {
    int n = 4;
    double x = 1.5;

    // 调用递归函数
    double result = P(n, x);

    // 输出结果
    cout << "勒让德多项式 P_" << n << "(" << x << ") 的值为: " << result << endl;

    return 0;
}

// 递归函数定义
double P(int n, double x) {
    // 1. 基准情况（终止条件）：对应公式中的 n=0
    if (n == 0) {
        return 1.0;
    }
    // 2. 基准情况（终止条件）：对应公式中的 n=1
    else if (n == 1) {
        return x;
    }
    // 3. 递归步骤：对应公式中的 n > 1
    // 公式：((2n - 1) * x * P_{n-1}(x) - (n - 1) * P_{n-2}(x)) / n
    else {
        return ((2 * n - 1) * x * P(n - 1, x) - (n - 1) * P(n - 2, x)) / n;
    }
}