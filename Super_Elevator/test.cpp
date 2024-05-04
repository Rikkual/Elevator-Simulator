//
// Created by Rikkual on 2024/4/16.
//

#include <bits/stdc++.h>
#include <conio.h>
using namespace std;


int main() {
    char choice = _getch(); // 获取用户输入的第一个字符
    cout << choice; // 在屏幕上显示输入的字符
    while (_kbhit()) _getch(); // 清空输入缓冲区

    cin.get(); // 等待用户输入
    return 0;
}