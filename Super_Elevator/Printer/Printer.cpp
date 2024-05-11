//
// Created by Rikkual on 2024/4/25.
//

#include "Printer.h"
#include "TerminalControl.h"

#ifdef DEBUG_ABOUT_JUMP
void Printer::printOpenDoor() {
    ifstream file("OpenDoor.txt");
    int x = 1, y = 1;
    string str;
    while(getline(file, str)) {
        gotoxy(x, y++);
        cout << str;
    }
    file.close();
}
#endif

void Printer::setxy(int x, int y) {
    curX = x; curY = y;
}

int Printer::getX() const {
    return curX;
}

int Printer::getY() const {
    return curY;
}

void Printer::printCloseDoor() {
    ifstream file("CloseDoor.txt");
    int x = 1, y = 1;
    string str;
    while(getline(file, str)) {
        gotoxy(x, y++);
        cout << str;
    }
    file.close();
}

string transStr(const string &str) {
    string res = {}, s = {};
    bool flag = true;
    for(auto it : str) {
        if(flag) {
            if(it == '[') {
                flag = false;
                continue;
            }
            res += it;
        }
        else {
            if(it == ']') {
                flag = true;
                res += charMap.at(s);
                s = {};
                continue;
            }
            s += it;
        }
    }
    return res;
}

void Printer::printAbout() {
    ifstream file("About.txt");
    int x = ABOUT_X, y = ABOUT_Y;
    string str;
    while(getline(file, str)) {
        gotoxy(x, y++);
        str = transStr(str);
        cout << str << endl;
        if(COUT_ANIMATION) mySleep(ANIMATION_SPEED);
    }
    file.close();
}

void Printer::clearLine(int x, int y, int len, bool animation) {
    gotoxy(x, y);
    for(int i = 1; i <= len; i++) {
        cout << " ";
    }
    if(animation && COUT_ANIMATION) mySleep(ANIMATION_SPEED);
}

void Printer::clearLine(int x, int y, bool animation) {
    clearLine(x, y, DELETE_LINE_LENGTH, animation);
}

void Printer::clearAbout(int y) {
    // for(int i = 1; i <= 18; i++) {
    for(int i = y; i >= 1; i--) {
        clearLine(40, i);
    }
}

void Printer::closeDoor() {
    for(int i = 10; i >= 1; i--) {
        for(int j = 2; j <= 17; j++) {
            gotoxy(17 - i, j);
            cout << "░▓";
            gotoxy(17 + i - 1, j);
            cout << "▓░";
        }
        mySleep(DOOR_SPEED);
    }
}

void Printer::openDoor() {
    for(int i = 1; i <= 10; i++) {
        for(int j = 2; j <= 17; j++) {
            gotoxy(17 - i, j);
            cout << "▓ ";
            gotoxy(17 + i - 1, j);
            cout << " ▓";
        }
        mySleep(DOOR_SPEED);
    }
}

void Printer::printFloorBase(int floor) {
    int x = FLOOR_DISPLAY_X, y = FLOOR_DISPLAY_Y;
    gotoxy(x - 1, y - 1);  cout << "╔═╦═╗";
    gotoxy(x - 1, y + 0);  cout << "║ ║ ║";
    gotoxy(x - 1, y + 1);  cout << "╚═╩═╝";
    gotoxy(x + 0, y + 0);  cout << floor;
}

void Printer::printDevisionLine(int &x, int &y, int len) {
    gotoxy(x, y);
    for(int i = 1; i <= len; i++) cout << "=";
    cout << endl; y++;
    if(COUT_ANIMATION) mySleep(ANIMATION_SPEED);
}

void Printer::setMessage(const string& _message) {
    message = _message;
}

string Printer::Message() const {
    return message;
}

void Printer::printOptions(int x, int y, const std::vector<string>& options) {
    Printer::printDevisionLine(x, y);
    gotoxy(x, y++);
    cout << message;
    if(COUT_ANIMATION) mySleep(ANIMATION_SPEED);

    Printer::printDevisionLine(x, y);
    for(int i = 0; i < (int)options.size(); i++) {
        gotoxy(x, y++);
        cout << "  " << i + 1 << ". " << options[i] << endl;
        if(COUT_ANIMATION) mySleep(ANIMATION_SPEED);
    }

    Printer::printDevisionLine(x, y);
    gotoxy(x, y++);
    cout << "请输入选项：";
}

void Printer::print(const string &message, int x, int y) {
    gotoxy(x, y);
    cout << message;
    curY++;
}

void Printer::print(const string &message) {
    print(message, curX, curY);
}
