/*
程序功能：
	- 模式1：从标准输入读取文本，统计“数字字符/空白字符/其他字符”的个数；
	- 模式2（默认）：从标准输入读取文本，统计“行数/单词数/字符数”。
	- Windows 控制台下已设置输出编码为 UTF-8 以便显示中文。

使用方法：
	1) 交互式输入：
		 lab1_4.exe 1   或   lab1_4.exe 2
		 然后输入要统计的文本；在 Windows 下按 Ctrl+Z 再回车 表示输入结束。
		 例如：
			 lab1_4.exe 1
			 123 abc\tX\n
			 Ctrl+Z 回车

参数说明：
	- 无参或参数无效：提示“未知的模式”，并自动使用模式2；
	- '1' 选择模式1（digit/white/other），'2' 选择模式2（lines/words/chars）。

输出说明：
	- 模式1：打印“数字字符、空白字符、其他字符”的计数；
	- 模式2：打印“行数、单词数、字符数”的计数（以空白划分单词）。

注意：
	- 在某些 Windows 终端中，Ctrl+Z 可能作为字符(ASCII 26)传入，本程序将其视为输入结束标记，不计入统计。
*/
#include <iostream>
#include <cctype>
#ifdef _WIN32
#include <windows.h>
#endif

int main(int argc, char **argv) {

	// 设置控制台编码为UTF-8（解决中文乱码）
#ifdef _WIN32
	SetConsoleOutputCP(65001);
#endif

	// 模式选择：
	//   参数为空或不正确时显示用法并默认使用模式2（行/单词/字符统计）
	//   使用方式举例： lab1_4.exe 1   -> 模式1: 统计数字/空白/其他
	//                lab1_4.exe 2   -> 模式2: 统计行/单词/字符
	int mode = 2;
	if (argc >= 2) {
		if (argv[1][0] == '1') mode = 1;
		else if (argv[1][0] == '2') mode = 2;
		else {
			std::cerr << "未知的模式，支持 1 (digit/white/other) 或 2 (lines/words/chars)，使用默认模式2。" << std::endl;
		}
	}

	int ch;
	if (mode == 1) {
		// 模式1：统计数字字符、空白字符和其他字符
		long long nDigit = 0, nWhite = 0, nOther = 0;
		while ((ch = std::cin.get()) != EOF) {
			// 在 Windows 控制台中，Ctrl+Z 会产生 ASCII 26 (SUB)。
			// 有时终端会把它作为输入字符传给程序，而不是直接结束输入。
			// 为避免把 Ctrl+Z 计入统计，这里把 26 当作 EOF 处理（不计数，直接跳出）。
			if (ch == 26) break;
			unsigned char uch = static_cast<unsigned char>(ch);
			// 按分析要求：使用 switch 语句判断字符种类
			int kind;
			if (std::isdigit(uch)) kind = 0;      // 数字
			else if (std::isspace(uch)) kind = 1; // 空白
			else kind = 2;                        // 其他
			switch (kind) {
			case 0:
				++nDigit;
				break;
			case 1:
				++nWhite;
				break;
			case 2:
				++nOther;
				break;
			}
		}
		std::cout << "数字字符: " << nDigit << std::endl;
		std::cout << "空白字符: " << nWhite << std::endl;
		std::cout << "其他字符: " << nOther << std::endl;
	} else {
		// 模式2：统计行数、单词数和字符数（默认）
		long long nLines = 1, nWords = 0, nChars = 0;
		bool inWord = false;
		while ((ch = std::cin.get()) != EOF) {
			// 同样在模式2 中也对 ASCII 26 做特殊处理，避免被计入字符或单词统计
			if (ch == 26) break;
			unsigned char uch = static_cast<unsigned char>(ch);
			++nChars;
			if (ch == '\n') ++nLines;
			if (std::isspace(uch)) {
				inWord = false;
			} else {
				if (!inWord) {
					inWord = true;
					++nWords;
				}
			}
		}
		std::cout << "行数: " << nLines << std::endl;
		std::cout << "单词数: " << nWords << std::endl;
		std::cout << "字符数: " << nChars << std::endl;
	}

	return 0;
}

