#include "rect.h"

// 构造函数实现
// 注意：缺省参数（默认参数）只能在声明中指定，定义中不能再次指定
Rectangle::Rectangle(int left, int top, int right, int bottom) :
    m_left(left), m_right(right), m_top(top), m_bottom(bottom) {
    // 构造函数，使用初始化列表初始化成员变量
}

// 复制构造函数实现
Rectangle::Rectangle(const Rectangle & rhs) {
    // 将传入对象 rhs 的属性值拷贝给当前对象
    m_left = rhs.m_left;
    m_top = rhs.m_top;
    m_right = rhs.m_right;
    m_bottom = rhs.m_bottom;
    
    // 如果想验证它被调用了，可以加一句：
    // cout << "Copy constructor called!" << endl;
}

void Rectangle::show() { // 显示左上点和右下点的坐标
    cout << "left-top point is (" << m_left
         << "," << m_top << ")" << '\n';
    cout << "right-bottom point is (" << m_right
         << "," << m_bottom << ")" << '\n';
}

void Rectangle::assign(int left, int top, int right, int bottom) {
    m_left = left;
    m_right = right;
    m_top = top;
    m_bottom = bottom;
}

int Rectangle::area() {
    return (m_right - m_left) * (m_bottom - m_top);
}

int Rectangle::perimeter() {
    return 2 * ((m_right - m_left) + (m_bottom - m_top));
}