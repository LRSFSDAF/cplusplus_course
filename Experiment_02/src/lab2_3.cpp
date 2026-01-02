/*
程序功能：
    读取一行字符串，过滤出字母字符并统一为小写，然后判断是否为回文。

使用方法：
    - 运行程序后根据提示输入一行文本（可包含空格/符号/大小写混合）；程序会输出是否为回文。
    - 可通过管道或重定向提供输入，例如：`type input.txt | .\lab2_3.exe`。

实现说明：
    - 使用 `std::getline` 读取整行；遍历输入，仅保留字母字符（`std::isalpha`），并使用 `std::tolower` 统一为小写。
    - 使用字符串迭代器（等价于指针）从两端向中间比较，判断是否对称。
    - Windows 控制台输出编码设置为 UTF-8，方便显示中文提示。

错误与退出码：
    - 若输入流出现错误（如立即 EOF），程序输出空结果并以非零退出码（1）结束；
    - 正常执行（无异常）返回 0。

Windows 注意：
    - 若在非 UTF-8 终端运行，可先执行 `chcp 65001` 以避免提示信息乱码。
*/
#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {

    // 设置控制台编码为UTF-8（解决中文乱码）
    #ifdef _WIN32
        SetConsoleOutputCP(65001);
    #endif

    string input;
    
    cout << "Please input a string ...\n";
    getline(cin, input);
    
    // 清理字符串：只保留字母并转为小写
    string cleaned;
    for (char ch : input) {
        if (isalpha(ch)) {
            cleaned += tolower(ch);
        }
    }
    
    // 使用迭代器（本质也是指针）判断回文
    bool is_palindrome = true;
    auto left = cleaned.begin();      // 指向开头
    auto right = cleaned.end() - 1;   // 指向结尾
    
    while (left < right) {
        if (*left != *right) {
            is_palindrome = false;
            break;
        }
        ++left;
        --right;
    }
    
    // 输出结果
    if (is_palindrome) {
        cout << "The string is a palindrome\n";
    } else {
        cout << "The string isn't a palindrome\n";
    }

    return 0;
}