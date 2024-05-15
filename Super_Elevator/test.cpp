//
// Created by Rikkual on 2024/4/16.
//

#include <bits/stdc++.h>
#include <conio.h>
using namespace std;



void B() {
    static int cnt = 7;
    cout << ++cnt << endl;
}

int main() {
    B(); B(); B();
    int x; cin >> x;
    return 0;
}