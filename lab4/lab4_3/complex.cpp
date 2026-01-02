#include "complex.h"
#include <cmath> // 用于 fabs (比较浮点数)

// 【必须】在类外初始化静态成员变量
int Complex::m_count = 0;

// 构造函数
Complex::Complex(double real, double imag) 
    : m_real(real), m_imag(imag) {
    m_count++; // 创建对象，计数 +1
}

// 复制构造函数
Complex::Complex(const Complex &other) 
    : m_real(other.m_real), m_imag(other.m_imag) {
    m_count++; // 复制产生新对象，计数 +1
}

// 析构函数
Complex::~Complex() {
    m_count--; // 对象销毁，计数 -1
}

// 静态成员函数
int Complex::number() {
    return m_count;
}

void Complex::set(double r, double i) {
    m_real = r; m_imag = i;
}

// 重载赋值运算符 "="
Complex& Complex::operator=(const Complex &rhs) {
    // 1. 检查自赋值 (a = a)
    if (this == &rhs) {
        return *this;
    }
    // 2. 赋值
    m_real = rhs.m_real;
    m_imag = rhs.m_imag;
    
    // 注意：赋值操作不产生新对象，所以 m_count 不用变
    return *this; // 支持链式赋值 a = b = c
}

// 重载 "+"
Complex operator+(const Complex &lhs, const Complex &rhs) {
    return Complex(lhs.m_real + rhs.m_real, lhs.m_imag + rhs.m_imag);
}

// 重载 "-"
Complex operator-(const Complex &lhs, const Complex &rhs) {
    return Complex(lhs.m_real - rhs.m_real, lhs.m_imag - rhs.m_imag);
}

// 重载 "*" (ac-bd, bc+ad)
Complex operator*(const Complex &lhs, const Complex &rhs) {
    double r = lhs.m_real * rhs.m_real - lhs.m_imag * rhs.m_imag;
    double i = lhs.m_imag * rhs.m_real + lhs.m_real * rhs.m_imag;
    return Complex(r, i);
}

// 重载 "/" (分母实数化)
Complex operator/(const Complex &lhs, const Complex &rhs) {
    double denominator = rhs.m_real * rhs.m_real + rhs.m_imag * rhs.m_imag;
    // 简单处理除以0的情况
    if (denominator == 0) return Complex(0, 0); 

    // 复数除法公式（分子分母同乘分母的共轭）：
    // (a+bi)/(c+di) = (ac+bd)/(c^2+d^2) + (bc-ad)/(c^2+d^2)i

    double r = (lhs.m_real * rhs.m_real + lhs.m_imag * rhs.m_imag) / denominator;
    double i = (lhs.m_imag * rhs.m_real - lhs.m_real * rhs.m_imag) / denominator;
    return Complex(r, i);
}

// 重载 "==" (浮点数比较需要注意精度，这里简化处理)
bool operator==(const Complex &lhs, const Complex &rhs) {
    return (lhs.m_real == rhs.m_real) && (lhs.m_imag == rhs.m_imag);
}

// 重载 "!="
bool operator!=(const Complex &lhs, const Complex &rhs) {
    return !(lhs == rhs);
}

// 重载 "<<"
ostream& operator<<(ostream &os, const Complex &rhs) {
    if (rhs.m_imag >= 0)
        os << rhs.m_real << "+" << rhs.m_imag << "i";
    else
        os << rhs.m_real << rhs.m_imag << "i";
    return os;
}