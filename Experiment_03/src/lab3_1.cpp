#include <iostream>
#include <cmath>    // 必须包含，用于使用 fabs() 求绝对值
#include <iomanip>  // 选含，用于控制输出小数位数

using namespace std;

// 函数声明：对应题目要求的 double sroot(double val)
double sroot(double val);

int main() {
    double number;
    
    cout << "请输入一个待求平方根的数: ";
    cin >> number;

    // 题目要求：在主调函数中判断输入的正负
    if (number < 0) {
        // 为负则输出错误信息
        cout << "Error: 输入的数字不能为负数！" << endl;
    } else {
        // 为正则调用函数并输出结果
        double result = sroot(number);
        cout << number << " 的平方根是: " << result << endl;
        
        // 验证一下（可以不写，但在实验报告中用来验证正确性很好）
        // cout << "标准库 sqrt() 结果对比: " << sqrt(number) << endl; 
    }

    return 0;
}

// 函数定义：利用迭代法求平方根
double sroot(double val) {
    // 特殊情况处理：如果是0，直接返回0，防止下面除以0的错误
    if (val == 0) return 0;

    // 根据题目提示：x1 = a / 2
    double x_old = val / 2.0; 
    double x_new;

    // 迭代过程
    while (true) {
        // 根据公式：x_{n+1} = (x_n + a/x_n) / 2
        x_new = (x_old + val / x_old) / 2.0;

        // 迭代结束条件的判断（关键点！）
        // 计算机中浮点数不能直接用 == 比较，需要判断两者的差值是否小于一个极小值（如 1e-6）
        if (fabs(x_new - x_old) < 1e-6) {
            break; // 如果两次迭代结果极其接近，说明已经求得近似解，跳出循环
        }

        // 更新 x_n，准备下一次迭代
        x_old = x_new;
    }

    return x_new;
}