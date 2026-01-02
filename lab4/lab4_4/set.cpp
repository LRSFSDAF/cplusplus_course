#include "Set.h"

// 构造函数：遍历输入的 vector，利用 insert 去重
Set::Set(const vector<char> &elem) {
    for (char c : elem) {
        insert(c);
    }
}

// 判断元素是否存在
bool Set::is_elem(char elem) {
    // 使用 std::find 查找元素
    auto it = find(m_elems.begin(), m_elems.end(), elem);
    return it != m_elems.end();
}

// 插入元素：集合的特性是元素唯一，所以插入前要检查
void Set::insert(char elem) {
    if (!is_elem(elem)) {
        m_elems.push_back(elem);
    }
}

// 删除元素
void Set::erase(char elem) {
    auto it = find(m_elems.begin(), m_elems.end(), elem);
    if (it != m_elems.end()) {
        m_elems.erase(it);
    }
}

// 求交集：两个集合中都有的元素
Set Set::common(const Set &s) {
    Set result;
    for (char c : m_elems) {
        // 因为 s 是 const 引用，而 is_elem 在头文件中没声明为 const，
        // 这里直接在 vector 中查找更稳妥，或者你可以修改头文件加 const
        auto it = find(s.m_elems.begin(), s.m_elems.end(), c);
        if (it != s.m_elems.end()) {
            result.insert(c);
        }
    }
    return result;
}

// 求并集：两个集合所有的元素（自动去重）
Set Set::sum(const Set &s) {
    Set result = *this; // 先把自己的元素拷贝一份
    for (char c : s.m_elems) {
        result.insert(c); // 再把另一个集合的元素插进去，insert会处理重复
    }
    return result;
}

// 赋值运算符重载
Set& Set::operator=(const Set &s) {
    if (this == &s) { // 防止自赋值
        return *this;
    }
    this->m_elems = s.m_elems; // vector 自带深拷贝功能
    return *this;
}

// 复制构造函数
Set::Set(const Set &s) {
    this->m_elems = s.m_elems; // vector 自带深拷贝
}

// 重载输出运算符
ostream& operator<<(ostream &os, const Set &s) {
    for (size_t i = 0; i < s.m_elems.size(); i++) {
        os << s.m_elems[i];
        if (i != s.m_elems.size() - 1) {
            os << " "; // 元素之间加个空格，美观一点
        }
    }
    return os;
}

/*// 详细解释输出运算符重载的实现步骤：
// 1. 函数头
// ostream& os: 这里的 os 其实就是传入的 cout。传引用是因为 cout 不能被复制。
// const Set &s: 这里的 s 就是你要打印的那个集合对象。
ostream& operator<<(ostream &os, const Set &s) {

    // 2. 循环遍历
    // s.m_elems.size() 获取 vector 里有多少个元素
    // size_t 是一个无符号整数类型，专门用来表示大小，你也可以当成 int 看
    for (size_t i = 0; i < s.m_elems.size(); i++) {
        
        // 3. 核心输出
        // s.m_elems[i] 取出 vector 第 i 个字符
        // os << ... 等价于 cout << ...
        // 这句话把字符塞进了输出流里
        os << s.m_elems[i];

        // 4. 格式美化（判断是否是最后一个元素）
        // 如果 vector 有 3 个元素，下标是 0, 1, 2。size是3。
        // 当 i=0 时，不是最后一个，打印空格 -> "a "
        // 当 i=1 时，不是最后一个，打印空格 -> "a b "
        // 当 i=2 时，是最后一个 (2 == 3-1)，不执行 if，不打印空格 -> "a b c"
        // 这样输出的结果最后面不会多带一个难看的空格。
        if (i != s.m_elems.size() - 1) {
            os << " "; 
        }
    }

    // 5. 返回流对象
    // 为什么要返回？为了支持“链式调用”。
    // 比如: cout << s1 << endl;
    // 这一步运行完返回了 os (也就是 cout)，代码变成了 cout << endl; 才能继续运行。
    return os; 
}
*/