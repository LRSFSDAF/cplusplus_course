#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex {
public:
    // 1. 构造函数
    // 注意：为了统计个数，不能再用 =default，必须手动实现
    Complex(double real = 0.0, double imag = 0.0);

    // 2. 复制构造函数
    Complex(const Complex &other);

    // 3. 析构函数
    ~Complex();

    // 4. 静态成员函数：返回当前对象个数
    static int number();

    // 获取实部虚部
    double real() const { return m_real; }
    double imag() const { return m_imag; }
    void set(double r, double i);

    // --- 运算符重载区域 ---

    // (1) 赋值运算符 "="
    // 规定：必须是类的成员函数
    Complex& operator=(const Complex &rhs);

    // (2) 四则运算 "+, -, *, /"
    // lhs: Left Hand Side (左操作数)，比如 c1 + c2 中的 c1
    // rhs: Right Hand Side (右操作数)，比如 c1 + c2 中的 c2
    // 建议：定义为友元函数，支持交换律（如 1.5 + c）
    friend Complex operator+(const Complex &lhs, const Complex &rhs);
    friend Complex operator-(const Complex &lhs, const Complex &rhs);
    friend Complex operator*(const Complex &lhs, const Complex &rhs);
    friend Complex operator/(const Complex &lhs, const Complex &rhs);

    // (3) 比较运算符 "==, !="
    // 建议：定义为友元函数
    friend bool operator==(const Complex &lhs, const Complex &rhs);
    friend bool operator!=(const Complex &lhs, const Complex &rhs);

    // (4) 输出运算符 "<<" (之前已实现)
    friend ostream& operator<<(ostream &os, const Complex &rhs);

private:
    double m_real;
    double m_imag;

    // 【关键】静态数据成员，用于计数
    static int m_count;
};

#endif