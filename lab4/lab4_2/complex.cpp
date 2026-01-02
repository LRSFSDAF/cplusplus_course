#include "complex.h"

// 带参构造函数实现
Complex::Complex(double real, double imag) 
    : m_real(real), m_imag(imag) {
    // 使用初始化列表赋值
}

// 【关键点】复制构造函数实现
Complex::Complex(const Complex &other) {
    m_real = other.m_real;
    m_imag = other.m_imag;
    cout << "Copy constructor called." << endl; // 打印日志方便验证
}

// 析构函数实现
Complex::~Complex() {
    // 简单类型无需释放内存，这里打印日志仅作演示
    // cout << "Destructor called." << endl; 
}

// 设置数值
void Complex::set(double r, double i) {
    m_real = r;
    m_imag = i;
}

// 【关键点】重载 << 运算符实现
ostream& operator<<(ostream &os, const Complex &rhs) {
    // 格式化输出：a + bi
    if (rhs.m_imag >= 0) {
        // 如果虚部是正数，输出 "实部+虚部i"
        os << rhs.m_real << "+" << rhs.m_imag << "i";
    } else {
        // 如果虚部是负数，直接输出 "实部虚部i" (负号自带)
        os << rhs.m_real << rhs.m_imag << "i";
    }
    return os; // 返回流对象以支持链式调用 (cout << c1 << c2)
}