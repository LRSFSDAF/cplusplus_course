/*
程序功能：
    模拟经典约瑟夫问题：共有 n 个人围成一圈，依次从 1 报数，报到 m 的人出圈，重复直至剩下最后一人。

使用方法：
    - 交互式：运行程序后按提示依次输入总人数 n 和报数上限 m（均为正整数），程序会按顺序输出每个出局者及最终幸存者。
    - 可通过重定向或管道提供输入，例如：`echo "10 3" | .\lab2_4.exe`（注意输入格式与提示保持一致）。

实现说明：
    - 使用 `vector<bool>` 维护每个人是否仍在圈内；通过循环下标 `index` 和计数器 `count` 模拟报数过程。
    - 每当计数达到 m，就将该位置设为 false（出局）并打印信息；剩余人数 `left` 减 1。
    - Windows 控制台下设置输出编码为 UTF-8，保证中文提示正确显示。

错误与退出码：
    - 若输入失败或 n/m 非正数，程序行为未定义（当前实现未做额外校验，输入异常时可能留下残余状态）；
    - 正常执行结束返回 0。

Windows 注意：
    - 若终端非 UTF-8，可先执行 `chcp 65001` 以避免中文提示乱码。

示例（n=10, m=3）：
    输入：
        请输入总人数n: 10
        请输入报数上限m: 3
    输出（部分）：
        第1个出局的是: 3
        第2个出局的是: 6
        第3个出局的是: 9
        第4个出局的是: 2
        第5个出局的是: 7
        第6个出局的是: 1
        第7个出局的是: 8
        第8个出局的是: 5
        第9个出局的是: 10
    
最后留下的是: 4
*/
#if _WIN32
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

     int n, m;
    
    // 输入总人数n和报数上限m
    cout << "请输入总人数n: ";
    cin >> n;
    cout << "请输入报数上限m: ";
    cin >> m;
    
    // 初始化vector，所有元素为true表示在圈内
    vector<bool> circle(n, true);
    
    int index = 0;  // 当前报数人的下标
    int count = 0;  // 报数计数器
    int left = n;   // 剩余在圈内的人数
    
    // 当剩余人数大于1时继续游戏
    while (left > 1) {
        // 如果当前位置的人在圈内
        if (circle[index]) {
            count++;  // 报数
            
            // 如果报数到m
            if (count == m) {
                circle[index] = false;  // 出局
                left--;                 // 剩余人数减1
                count = 0;              // 重置计数器
                // 显示出局信息
                cout << "第" << n - left << "个出局的是: " << index + 1 << endl;
            }
        }
        
        // 移动到下一个人，使用取余实现循环
        index = (index + 1) % n;
    }
    
    // 找到最后留下的人
    for (int i = 0; i < n; i++) {
        if (circle[i]) {
            cout << "\n最后留下的是: " << i + 1 << endl;
            break;
        }
    }

    return 0;
}
    