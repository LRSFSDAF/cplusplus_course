/*
程序功能：
    计算一元二次方程 ax^2 + bx + c = 0 的根（包含两个不相等实根、两个相等实根或一对共轭复根），
    并处理 a≈0 的退化情形（一次方程或常数方程）。

使用方法：
    - 在标准输入中一行输入 3 个实数：a b c，然后回车。例如：
            1 2 1
    - 如果一行中输入了多于三个数，程序只使用前三个系数，并给出警告。
    - Windows 控制台下，程序已将输出编码设置为 UTF-8，便于显示中文。

输出说明：
    - 打印判别式 Δ=b^2-4ac（按 fixed 格式、6 位小数）以及对应的根；
    - 当 a≈0 时，给出一次方程解或“无穷多解/无解”的提示。

错误与退出码：
    - 读入失败（如 EOF 或非数值）会报错并以非零退出码（1）结束。
*/
#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>
#ifdef _WIN32
#include <windows.h>
#endif

int main() {

// 设置控制台编码为UTF-8（解决中文乱码）
#ifdef _WIN32
    SetConsoleOutputCP(65001);
#endif

    // 读取一整行并解析三个系数 a, b, c，避免为检测多余输入而发生二次阻塞读取
    std::string line;
    if (!std::getline(std::cin, line)) {
        std::cerr << "输入错误：未读取到任何内容（可能是 EOF）" << std::endl;
        return 1;
    }

    double a, b, c;
    std::istringstream iss(line);
    if (!(iss >> a >> b >> c)) {
        std::cerr << "输入错误：请在一行中提供三个数值 a b c" << std::endl;
        return 1;
    }
    // 检测该行是否还有多余输入（例如 "1 2 3 4"），如有则仅提示并忽略
    std::string extra;
    if (iss >> extra) {
        std::cerr << "警告：输入多于三个数，程序只使用前三个系数 (a, b, c): "
                  << a << ", " << b << ", " << c << std::endl;
    }

    const double eps = 1e-12;

    // 处理 a == 0 的情况（退化为一次或常数方程）
    if (std::fabs(a) < eps) {
        if (std::fabs(b) < eps) {
            if (std::fabs(c) < eps) {
                std::cout << "方程有无限多解。" << std::endl;
            } else {
                std::cout << "方程无解。" << std::endl;
            }
        } else {
            double x = -c / b;
            std::cout << "这是一个一元一次方程，实根为: x = " << std::setprecision(6) << std::fixed << x << std::endl;
        }
        return 0;
    }

    double delta = b * b - 4.0 * a * c;

    if (delta > eps) {
        double sqrt_d = std::sqrt(delta);
        double x1 = (-b + sqrt_d) / (2.0 * a);
        double x2 = (-b - sqrt_d) / (2.0 * a);
        std::cout << "Delta = " << std::setprecision(6) << std::fixed << delta << std::endl;
        std::cout << "有两个不相等的实根: x1 = " << x1 << ", x2 = " << x2 << std::endl;
    } else if (std::fabs(delta) <= eps) {
        double x = -b / (2.0 * a);
        std::cout << "Delta = 0" << std::endl;
        std::cout << "有两个相等的实根: x = " << std::setprecision(6) << std::fixed << x << std::endl;
    } else {
        // 两个共轭复数根
        double real = -b / (2.0 * a);
        double imag = std::sqrt(-delta) / (2.0 * a);
        std::cout << "Delta = " << std::setprecision(6) << std::fixed << delta << std::endl;
        std::cout << "有两个复数根: x1 = " << std::setprecision(6) << std::fixed << real << "+" << imag << "i, x2 = " << real << "-" << imag << "i" << std::endl;
    }

    return 0;
}