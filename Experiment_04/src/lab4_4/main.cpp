#include "Set.h"
#include <vector>

int main() {
    // 注意：temp1 中有重复的 's' 和 'f'，Set构造函数需要能去除它们
    vector<char> temp1 = {'a', 's', 'd', 'f', 'g', 's', 'f'}; 
    vector<char> temp2 = {'a', 'c', 'v', 'f', 't', 'y', 'e', 'r'};

    Set s1(temp1), s2(temp2), s3, s4;
    
    // 测试 is_elem
    cout << "Is 'a' in s1? " << (s1.is_elem('a') ? "Yes" : "No") << endl;

    // 测试 insert
    s1.insert('p');
    cout << "s1={" << s1 << "}" << endl;

    // 测试 erase
    s2.erase('t');
    cout << "s2={" << s2 << "}" << endl;
    cout << s2 << endl;

    // 测试交集
    s3 = s1.common(s2);
    // 测试并集
    s4 = s1.sum(s2);

    cout << "s3={" << s3 << "}" << endl;
    cout << "s4={" << s4 << "}" << endl;

    // 测试复制构造函数
    Set s5(s1);
    cout << "s5={" << s5 << "}" << endl;

    // 测试赋值
    s5 = s4;
    cout << "s5={" << s5 << "}" << endl;

    return 0;
}