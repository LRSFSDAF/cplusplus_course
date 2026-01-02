#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex {
public:
    // 1. 默认构造函数（C++11 特性，使用编译器默认生成的）
    Complex() = default;

    // 带参构造函数
    Complex(double real, double imag);

    // 复制构造函数 (Copy Constructor)
    Complex(const Complex &other);

    // 析构函数 (Destructor)
    ~Complex();

    // 内联函数：获取实部和虚部
    // 建议加上 const 修饰，表示不会修改对象
    double real() const { return m_real; } 
    double imag() const { return m_imag; } 

    // 设置实部和虚部
    void set(double r, double i);

    // 重载输出运算符 "<<"
    // 必须定义为 friend 友元函数，因为它不是类的成员函数，而是 ostream 类的操作
    friend ostream& operator<<(ostream &os, const Complex &rhs);

private:
    double m_real;
    double m_imag;
};

#endif