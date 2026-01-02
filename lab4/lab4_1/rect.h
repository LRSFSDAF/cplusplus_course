#ifndef RECT_H
#define RECT_H
#include <iostream>
using namespace std;

class Rectangle {
    int m_left, m_top;
    int m_right, m_bottom;
public:
    // 构造函数，带缺省参数
    Rectangle(int left = 0, int top = 0, int right = 0, int bottom = 0);
    // 复制构造函数
    Rectangle(const Rectangle & rhs);
    
    // 析构函数，在此函数体为空
    ~Rectangle() {} 
    
    // 显示左上角与右下角坐标
    void show(); 
    
    // 设置矩形参数
    void assign(int left, int top, int right, int bottom); 
    
    // 计算矩形面积
    int area(); 
    
    // 计算矩形周长
    int perimeter(); 
};

#endif