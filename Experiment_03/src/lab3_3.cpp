#pragma region firstpart

// #include <iostream>
// using namespace std;

// // 函数声明
// void secret(char* data);
// void desecret(char data[]); // 数组形式参数本质上也是指针

// int main() {
//     // 定义字符数组，不能用字符串常量指针(const char*)，因为我们要修改它
//     char st[] = "This is a secret code!";
    
//     cout << "原始字符串: " << st << endl;
    
//     secret(st); // 调用加密
//     cout << "加密后: " << st << endl;
    
//     desecret(st); // 调用解密
//     cout << "解密后: " << st << endl;
    
//     return 0;
// }

// // ==========================================
// // 编写的函数实现
// // ==========================================

// // 加密函数
// void secret(char* data) {
//     // 循环直到遇到字符串结束符 '\0'
//     while (*data != '\0') {
//         // 如果是 'a' 到 'y' 之间的字符，ASCII码 +1
//         if (*data >= 'a' && *data <= 'y') {
//             (*data)++;
//         }
//         // 如果是 'z'，特殊处理变为 'a'
//         else if (*data == 'z') {
//             *data = 'a';
//         }
//         // 指针后移，指向下一个字符
//         data++;
//     }
// }

// // 解密函数
// void desecret(char data[]) {
//     int i = 0;
//     while (data[i] != '\0') {
//         // 加密的逆过程：'b' 到 'z' 减 1
//         if (data[i] >= 'b' && data[i] <= 'z') {
//             data[i]--;
//         }
//         // 'a' 还原为 'z'
//         else if (data[i] == 'a') {
//             data[i] = 'z';
//         }
//         i++;
//     }
// }

#pragma endregion

#pragma region thinkingpart
/*
1. 将 secret(char* data) 改为 secret(const char* data)，程序还能运行吗？为什么？
答案：不能运行（编译会报错）。
原因解析：
const char* 表示 “指向常量的指针”。一旦加上 const 修饰符，就意味着你向编译器承诺：在这个函数内部，绝不通过这个指针修改它所指向的数据。
然而在函数体中，代码 (*data)++ 和 *data = 'a' 试图修改内存中的字符。编译器检测到你违反了承诺，为了保护数据不被意外篡改，会报出错误（例如：assignment of read-only location）。

2.如果将两个函数中 else if 处的 else 去掉，对程序有何影响？使用数据 "I am a boy!" 重新测试看看。
答案：程序逻辑出错，导致字符 'y' 加密错误。
详细分析：
正常逻辑（有 else）：如果字符是 'y'，满足第一个条件变成 'z'，因为有 else，程序会跳过后续判断，处理下一个字符。
错误逻辑（去掉 else）：程序会发生 “连环修改”。
假设当前字符是 'y'。
执行第一个 if：'y' 在 'a'~'y' 之间，于是 'y' 变成了 'z'。
紧接着执行第二个 if：检查当前字符是否为 'z'？是！（因为它刚才被改成了 'z'）。于是 'z' 又被变成了 'a'。
"I am a boy!" 测试结果：
单词 boy 中的 y，本该加密成 z，结果变成了 a。
正确加密结果：I bn b bpz!
去掉 else 后的错误结果：I bn b bpa!
*/

#pragma endregion

#pragma region secondpart

#include <iostream>
using namespace std;

// 定义密钥，可以是任意整数
const int KEY = 5; 

void encrypt_with_key(char* str);
void decrypt_with_key(char* str);

int main() {
    char text[] = "Hello World! I am a student.";
    
    cout << "=== 带密钥加密演示 (Key=" << KEY << ") ===" << endl;
    cout << "原文: " << text << endl;
    
    encrypt_with_key(text);
    cout << "加密后: " << text << endl;
    
    decrypt_with_key(text);
    cout << "解密后: " << text << endl;
    
    return 0;
}

// 带密钥加密
void encrypt_with_key(char* str) {
    while (*str != '\0') {
        // 1. 取出当前字符的ASCII数值
        int val = (int)(*str);
        // 2. 加上密钥
        val = val + KEY;
        // 3. 对128求模
        *str = (char)(val % 128);
        
        str++;
    }
}

// 带密钥解密
void decrypt_with_key(char* str) {
    while (*str != '\0') {
        // 1. 取出数值
        int val = (int)(*str);
        // 2. 减去密钥
        val = val - KEY;
        
        // 3. 处理负数情况：如果减完是负数，需要加128再取模
        // 数学公式：(val - key + 128) % 128
        if (val < 0) {
            val += 128;
        }
        *str = (char)(val % 128);
        
        str++;
    }
}

#pragma endregion
