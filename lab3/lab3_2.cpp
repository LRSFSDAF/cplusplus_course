#include <iostream>
using namespace std;

/*
运行结果
305 300
400
705 400
300 400 0
300 400 400
*/


// 全局变量定义
int value1 = 300, value2 = 400, value3 = 500;

void funa(int value3) {
    static int value1 = 5; // 静态局部变量，只初始化一次
    value1 += value3;
    cout << value1 << ' ' << value3 << '\n';
}

void funb(int value1) {
    value1 = value2; // 这里修改的是形参（局部变量），不影响全局value1
    cout << value1 << '\n';
}

void func() {
    int value3 = 0; // 局部变量，遮蔽了全局value3
    cout << value1 << ' ' << value2 << ' ' << value3 << '\n';
    ::value3 -= 100; // 使用 :: 访问并修改全局变量value3
}

int main() {
    funa(value1);
    funb(value2);
    funa(value2);
    func();
    cout << value1 << ' ' << value2 << ' ' << value3 << '\n';
    return 0;
}