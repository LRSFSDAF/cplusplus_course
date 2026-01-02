#ifndef SET_H
#define SET_H

#include <iostream>
#include <vector>
#include <algorithm> // 必须包含，用于 find 函数

using namespace std;

class Set {
    vector<char> m_elems; // 数据成员，存放字符

public:
    Set() = default;
    
    // 构造函数：用 vector 初始化 Set
    Set(const vector<char> &elem); 
    
    // 判断 elem 是否为集合元素
    bool is_elem(char elem); 
    
    // 插入一个元素（需保证唯一性）
    void insert(char elem); 
    
    // 删除一个元素
    void erase(char elem); 
    
    // 求交集
    Set common(const Set &s); 
    
    // 求并集
    Set sum(const Set &s); 
    
    // 赋值运算符重载
    Set& operator=(const Set &s); 
    
    // 复制构造函数
    Set(const Set &s); 
    
    // 输出运算符重载
    friend ostream& operator<<(ostream &os, const Set &s);
};

#endif