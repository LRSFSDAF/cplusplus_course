#include <iostream>
#include "complex.h"

using namespace std;

int main() {
    // 1. 测试带参构造函数
    cout << "=== Test 1: Constructor & Output ===" << endl;
    Complex c1(3.0, 4.0);
    cout << "c1 = " << c1 << endl; // 应该输出 3+4i

    // 2. 测试 set 函数和负数虚部处理
    cout << "\n=== Test 2: Set function & Negative Imaginary ===" << endl;
    Complex c2;
    c2.set(5.0, -2.5);
    cout << "c2 = " << c2 << endl; // 应该输出 5-2.5i

    // 3. 测试复制构造函数
    cout << "\n=== Test 3: Copy Constructor ===" << endl;
    Complex c3(c1); // 用 c1 初始化 c3
    cout << "c3 (copy of c1) = " << c3 << endl;

    // 4. 验证实部虚部获取
    cout << "\n=== Test 4: Getters ===" << endl;
    cout << "Real part of c2: " << c2.real() << endl;
    cout << "Imag part of c2: " << c2.imag() << endl;

    return 0;
}

#pragma region tips

/*
Tips:
为什么要用 friend (友元)？
重载 << 时，左操作数是 cout (类型是 ostream)，右操作数是你的 Complex 对象。
如果写成成员函数，调用方式会变成 c1 << cout，这非常反直觉。
为了保持 cout << c1 的习惯，必须将函数定义在类外（全局函数）。但全局函数无法访问类的 private 成员（m_real），所以必须在类中声明它为 friend。
复制构造函数 (Copy Constructor)
形式必须是 ClassName(const ClassName &rhs)。
注意：参数必须是引用 (&)。如果是传值，调用复制构造函数时需要复制实参，这又会触发复制构造函数，导致无限递归（死循环）。
返回 ostream& 的原因
operator<< 的返回值类型是 ostream&，这是为了支持链式调用。
例如 cout << c1 << c2 << endl;。程序先执行 cout << c1，返回 cout 对象本身，然后变成 cout << c2，依此类推。
*/

#pragma endregion
