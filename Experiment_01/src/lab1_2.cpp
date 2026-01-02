/*
程序功能：
	读取一个整数 n，判断它是否为 3 的倍数、7 的倍数、两者都是，或两者都不是，并输出结果。

使用方法：
	- 在标准输入中一行输入一个整数 n，然后回车。例如：
			21
	- 程序使用 getline 读取整行后解析第一个整数；若同一行还有多余内容，会给出警告并忽略。
	- Windows 控制台下，程序已将输出编码设置为 UTF-8，便于显示中文。

输出说明：
	- 根据 n 对 3 和 7 的整除性，输出四种情况之一的中文提示。

错误与退出码：
	- 若未读到内容（EOF）或该行无法解析出整数，程序会报错并以非零退出码（1）结束。
*/
#include <iostream>
#include <sstream>
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    
// 设置控制台编码为UTF-8（解决中文乱码）
#ifdef _WIN32
    SetConsoleOutputCP(65001);
#endif

	// 读取一整行并解析一个整数 n，避免为了检测多余输入而二次读取阻塞
	std::string line;
	if (!std::getline(std::cin, line)) {
		std::cerr << "输入错误：未读取到任何内容（可能是 EOF）" << std::endl;
		return 1;
	}

	std::istringstream iss(line);
	long long n;
	if (!(iss >> n)) {
		std::cerr << "输入错误：请提供一个整数 n" << std::endl;
		return 1;
	}

	// 检测该行是否还有多余输入（例如输入了多个数或其他 token）
	std::string extra;
	if (iss >> extra) {
		std::cerr << "警告：输入多于一个数，程序只使用第一个整数 n = " << n << std::endl;
	}

	bool by3 = (n % 3 == 0);
	bool by7 = (n % 7 == 0);

	if (by3 && !by7) {
		std::cout << "是3的倍数,但不是7的倍数。" << std::endl;
	} else if (!by3 && by7) {
		std::cout << "不是3的倍数, 是7的倍数。" << std::endl;
	} else if (by3 && by7) {
		std::cout << "是3的倍数, 也是7的倍数。" << std::endl;
	} else {
	std::cout << "既不是3的倍数, 也不是7的倍数。" << std::endl;
	}

	return 0;
}
