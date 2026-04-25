#include "./include/obfusheader.h"
#include <bits/stdc++.h>

using namespace std;
 
int main() {
    // 示例：使用RND宏生成编译时常量随机数
    constexpr int randomNumber = RND(0, 10);
    std::cout << "Random Number: " << randomNumber << '\n';
 
    // 使用MAKEOBF创建加密字符串并解密显示
    const char* obfuscatedString = (char*)MAKEOBF("Hello, Secure World!");
    std::cout << "Decrypted String: " << obfuscatedString << std::endl;
 
    return 0;
}