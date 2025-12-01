/*
程序功能：
    - 第一步：使用指针按行优先顺序（左到右、上到下）为 5×5 整型矩阵赋值 1~25，并打印结果；
    - 第二步：仍通过指针算术将矩阵右上部分（不含主对角线）置为 0，再次打印矩阵。

使用方法：
    - 交互式：运行程序即可看到两个阶段的矩阵输出；无需额外输入。
    - 可通过重定向或管道将输出保存到文件，例如：`.\lab2_2.exe > result.txt`。

实现说明：
    - 使用固定大小数组 `int matrix[5][5]` 并通过指针遍历，实现连续内存赋值与按下标访问。
    - Windows 控制台下设置输出编码为 UTF-8 以正确显示中文描述。

错误与退出码：
    - 程序无用户输入，若在执行过程中无异常，始终以 0 退出。

Windows 注意：
    - 若终端非 UTF-8，可先执行 `chcp 65001` 以避免中文提示乱码。
*/
#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>
#include <vector>

using namespace std;

int main() {

    // 设置控制台编码为UTF-8（解决中文乱码）
    #ifdef _WIN32
        SetConsoleOutputCP(65001);
    #endif

    // 定义5×5二维向量（动态数组）
    const int ROWS = 5;
    const int COLS = 5;
    int matrix[ROWS][COLS];
    
    // 1. 用指针按照从左往右从上到下的次序依次给向量赋值
    int* ptr = &matrix[0][0]; // 指向第一个元素的指针
    int value = 1;
    
    for (int i = 0; i < ROWS * COLS; ++i) {
        *ptr = value; // 赋值
        ++value;      // 递增
        ++ptr;        // 移动到下一个元素
    }
    
    // 打印赋值后的矩阵
    cout << "赋值后的矩阵：" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
    // 2. 用指针将向量的右上部分全部置0（对角线不变）
    ptr = &matrix[0][0]; // 重新指向第一个元素
    
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (j > i) { // 右上部分（不包括对角线）
                *(ptr + i * COLS + j) = 0; // 使用指针算术访问元素
            }
        }
    }
    
    // 打印右上部分置0后的矩阵
    cout << "\n右上部分置0后的矩阵：" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
    return 0;
}