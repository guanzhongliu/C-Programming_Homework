/**
 * 1、输入一个长度小于100的字符串，判断其是否为回文串。
 **/
#include <iostream>

using namespace std;

int main() {
    cout << "Please give me a string, I'll tell you if it's a palindrome:" << endl;
    string a;
    cin >> a;
    for (int i = 0; i <= (a.length() - 1) / 2; i++) {
        if (a[i] != a[a.length() - 1 - i]) {
            std::cout << a << " is not a palindrome." << std::endl;
            return 0;
        }
    }
    std::cout << a << " is a palindrome." << std::endl;

    return 0;
}
