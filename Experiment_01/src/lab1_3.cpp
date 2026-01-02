/*
程序功能：
	逐行读取标准输入，对每行中的英文字母大小写互换：
		- a-z 转成 A-Z
		- A-Z 转成 a-z
	其它字符保持不变。处理结束后原样输出（逐行）。

使用方法：
	1) 交互输入：运行程序后键入若干行文本，最后在 Windows 控制台按 Ctrl+Z 再回车 结束输入。
		 示例：
			 输入:  Hello World!
			 输出:  hELLO wORLD!

实现说明：
	- 使用 std::getline 逐行读取，避免将末尾换行符留在缓冲导致重复处理。
	- 使用 ASCII 范围判断（'a'-'z' / 'A'-'Z'）手动加减 32 实现大小写互换；注释中保留了一个使用 std::islower/std::isupper 的备选实现。
	- 在 Windows 下设置输出代码页为 UTF-8 以便显示中文注释或混合文本。

输出格式：
	- 每处理一行后立即输出转换结果；除非已到达 EOF，否则补一个换行保持原有行结构。

错误与退出：
	- 若读取时遇到 EOF 正常结束（返回码 0）。
	- 本程序不对非 ASCII 英文字母进行大小写转换（例如中文、带重音的拉丁字母保持原样）。

注意：
	- Ctrl+Z 在某些终端可能作为字符 26 传入；此实现依赖 std::getline，到 EOF 时自然结束，不需要特别剔除 26。
*/
#include <iostream>
#include <string>
#include <cctype>
#ifdef _WIN32
#include <windows.h>
#endif

// int main() {
// 	std::string line;
// 	// 逐行读取输入，转换每行中的英文字母大小写并输出
// 	while (std::getline(std::cin, line)) {
// 		for (char &ch : line) {
// 			unsigned char uch = static_cast<unsigned char>(ch);
// 			if (std::islower(uch)) ch = static_cast<char>(std::toupper(uch));
// 			else if (std::isupper(uch)) ch = static_cast<char>(std::tolower(uch));
// 		}
// 		std::cout << line;
// 		if (!std::cin.eof()) std::cout << std::endl;
// 	}
// 	return 0;
// }

int main() {

// 设置控制台编码为UTF-8（解决中文乱码）
#ifdef _WIN32
    SetConsoleOutputCP(65001);
#endif

	std::string line;
	// 逐行读取输入，严格按 ASCII 分析将英文字母大小写互换（小写 -32-> 大写， 大写 +32-> 小写）
	while (std::getline(std::cin, line)) {
		for (char &ch : line) {
			unsigned char uc = static_cast<unsigned char>(ch);
			if (uc >= 'a' && uc <= 'z') {
				// 小写 -> 大写（ASCII 减 32）
				ch = static_cast<char>(uc - 32);
			} else if (uc >= 'A' && uc <= 'Z') {
				// 大写 -> 小写（ASCII 加 32）
				ch = static_cast<char>(uc + 32);
			}
		}
		std::cout << line;
		if (!std::cin.eof()) std::cout << std::endl;
	}
	return 0;
}