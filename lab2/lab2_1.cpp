/*
程序功能：
    将单个十进制非负整数转换为二进制表示并输出。

使用方法：
    - 交互式：运行程序后在提示符输入一个十进制非负整数并回车，例如：
            请输入一个十进制正整数: 13
        程序输出：二进制表示为: 1101
    - 可通过重定向或管道提供输入（例如：PowerShell 中使用管道：Get-Content input.txt | .\lab2_1.exe）。

实现说明：
    - 使用 `std::getline` 读取整行，然后用 `std::istringstream` 严格解析为单个整数，避免部分解析或阻塞读取。
    - 使用除二取余法生成二进制位，先将位累加到字符串然后反转得到最终二进制表示。

错误与退出码：
    - 当输入无法解析为单个整数、包含额外非空白字符或为负数时，程序会输出错误信息并以非零退出码（1）结束。
    - 当输入为 0 时，程序输出 0 并以 0 成功退出。

Windows 注意：
    - 程序尝试将控制台输出编码设置为 UTF-8（SetConsoleOutputCP(65001)），请确保终端使用 UTF-8 编码以正确显示中文提示。
*/

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm> // 用于 reverse 函数

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

int main() {

    // 设置控制台编码为UTF-8（解决中文乱码）
    #ifdef _WIN32
        SetConsoleOutputCP(65001);
    #endif

    // 读取一整行并严格解析为单个非负整数
    cout << "请输入一个十进制正整数: ";
    string line;
    if (!getline(cin, line)) {
        cerr << "输入错误：未读取到任何输入" << endl;
        return 1;
    }
    istringstream iss(line);
    long long decimal;
    if (!(iss >> decimal)) {
        cerr << "输入错误：请输入一个整数" << endl;
        return 1;
    }
    // 检查是否有多余内容（例如 12.3 或 12 abc）
    iss >> ws; // 跳过空白
    if (!iss.eof()) {
        cerr << "输入错误：请仅输入一个整数" << endl;
        return 1;
    }
    if (decimal < 0) {
        cerr << "输入错误：请输入非负整数" << endl;
        return 1;
    }

    // 处理特殊情况：输入为0
    if (decimal == 0) {
        cout << "二进制表示为: 0" << endl;
        return 0;
    }

    // 使用字符串存储二进制结果
    string binary = "";
    
    // 除二取余法
    while (decimal > 0) {
        // 获取当前位的余数
        int remainder = decimal % 2;
        // 将余数添加到字符串中
        binary += to_string(remainder);
        // 更新十进制数
        decimal /= 2;
    }
    
    // 反转字符串（因为除二取余得到的顺序是反的）
    reverse(binary.begin(), binary.end());
    
    cout << "二进制表示为: " << binary << endl;
    
    return 0;
}