#include "rect.h"
#include <cstdlib> // 对应 stdlib.h

int main() {
    Rectangle rect; // 使用默认参数调用构造函数
    rect.show();
    
    rect.assign(100, 200, 300, 400); // 修改对象属性
    rect.show();
    
    // 1. 创建一个初始对象 rect1
    cout << "=== Test 1: Create rect1 ===" << endl;
    Rectangle rect1(0, 0, 200, 200); 
    rect1.show();
    
    // 2. 修改 rect1 的值
    rect1.assign(100, 200, 300, 400);
    cout << "=== After assigning new values to rect1 ===" << endl;
    rect1.show();

    // 3. 【新增】调用复制构造函数
    // 语法：类名 新对象名(旧对象名);
    cout << "=== Test 2: Copy Constructor (rect2 copies rect1) ===" << endl;
    Rectangle rect2(rect1); 
    
    // 验证：rect2 的坐标应该和 rect1 目前的坐标完全一样
    cout << "Content of rect2:" << endl;
    rect2.show();

    // 4. 计算面积和周长
    cout << "Area of rect1: " << rect1.area() 
         << " Perimeter of rect1: " << rect1.perimeter() << endl;
         
    system("pause");
    return 0;
}

#pragma region thinkingpart

/*
1. 关于构造函数的默认参数
问题：将 Rectangle(double left=0... 改为 Rectangle(double left... （即去掉默认参数），程序还能正确运行吗？为什么？
助教回答：
不能运行（编译会报错）。
原因：在 main 函数的第 49 行，代码为 Rectangle rect;。这行代码在创建对象时没有传递任何参数，因此编译器会尝试调用类的默认构造函数（即无参构造函数或所有参数都有默认值的构造函数）。
如果你去掉了构造函数的默认值（=0），那么 Rectangle 类就不再拥有默认构造函数了。创建对象时必须提供 4 个参数，否则编译器不知道如何初始化 rect，从而报错。
2. 关于成员函数的参数
问题：为什么 show、area、perimeter 不需要带参数？以前写通用函数时是需要的。
助教回答：
这是面向对象编程（OOP）中封装的特性。
通用函数（面向过程）：数据和操作是分离的。函数不知道你要计算哪个矩形，所以必须把矩形的坐标作为参数传进去。
成员函数（面向对象）：数据（成员变量 m_left 等）和操作（area 等）被封装在一个类中。当你调用 rect.area() 时，有一个隐式的 this 指针 被传递给了函数。函数内部可以直接访问该对象自己的成员变量。简单说：因为它算的就是“它自己”的面积，所以不需要别人告诉它坐标是多少。
3. 关于 assign 函数的作用
问题 A：assign 函数的作用是什么？
助教回答：
assign 是一个典型的修改器（Mutator/Setter）。它的作用是在对象创建之后，修改对象的属性值。构造函数负责“出生”时的初始化，而 assign 负责“出生后”的状态改变。
问题 B：如果去掉了构造函数的默认参数，有人认为 Rectangle(...) 和 assign(...) 功能相同，能否去掉 assign？
助教回答：
不能去掉。 结果会导致程序中无法修改已有对象的值。
原因：
时机不同：Rectangle(...) 是构造函数，仅在对象创建的那一瞬间被调用，且只能调用一次。assign 是普通成员函数，可以在对象生命周期内随时调用，且可调用多次。
功能验证：如果你去掉 assign，main 函数中第 51 行 rect.assign(...) 就会报错。你无法复用 rect 这个对象来存储新的坐标，只能销毁它并创建一个新对象，这在效率和逻辑上都是不合理的。
4. 添加复制构造函数
要求：为 Rectangle 类添加复制构造函数 Rectangle(const Rectangle & rhs)。
助教解答：
在 rect.h 的 public 部分添加声明，并在 rect.cpp 中添加实现。
(虽然这个类只有 int 类型，编译器默认生成的浅拷贝就够用了，但手动写一遍有助于理解)。
*/

#pragma endregion
