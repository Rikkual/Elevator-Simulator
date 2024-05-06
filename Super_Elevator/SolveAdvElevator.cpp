//
// Created by Rikkual on 2024/5/3.
//

#include <bits/stdc++.h>
#include "AdvElevator.h"
#include "Logger.h"
#include "Printer.h"
#include "TerminalControl.h"

#include "config.h"

NAMESPACE_SOLVE_ADVELEVATOR

std::vector<string> options = {
        "电梯上行",
        "电梯下行",
        "打开日志",
        "退出程序",
};

bool executeOption(AdvElevator &elevator, Logger &logger, Printer &printer, int choice);
void elevatorUp(AdvElevator &elevator, Logger &logger, Printer &printer);
void elevatorDown(AdvElevator &elevator, Logger &logger, Printer &printer);
void elevatorUpDown(AdvElevator &elevator, Logger &logger, Printer &printer, bool up);
void getPersonInfo(AdvElevator &elevator, Logger &logger, Printer &printer, bool up);

void solve(AdvElevator &elevator, Logger &logger, Printer &printer) {
    int stx = INTERACT_X, sty = INTERACT_Y;
    printer.setMessage(std::format("Ciallo, 本电梯最高服务至{}层。", FLOOR));
    while(true) {
        int x = stx, y = sty;
        printer.printOptions(x, y, options);
        showCursor(); enableEcho();
        int choice; cin >> choice;
        hideCursor(); disableEcho();

        getCursorPos(x, y);
        Printer::clearAbout(y);
        if(!executeOption(elevator, logger, printer, choice)) break;
    }
}

bool executeOption(AdvElevator &elevator, Logger &logger, Printer &printer, int choice) {
    switch(choice) {
        case 1: // 上行
            elevatorUp(elevator, logger, printer);
            break;

        case 2: // 下行
            elevatorDown(elevator, logger, printer);
            break;

        case 3: // 打开日志文件
            logger.open();
            printer.setMessage(std::format("Ciallo, 本电梯最高服务至{}层。", FLOOR));
            break;

        case 4: // 退出程序
            logger.info("用户退出程序。");
            return false;

        default:
            logger.error("用户输入错误的选项！");
            printer.setMessage("请输入正确的选项！");
            break;

    }
    return true;
}

bool checkFloor(AdvElevator &elevator, Logger &logger, Printer &printer, int targetFloor, bool up);

void getPersonInfo(AdvElevator &elevator, Logger &logger, Printer &printer, bool up) {
    // bool down = !up;
    int x = INTERACT_X, y = INTERACT_Y;
    Printer::printDevisionLine(x, y);
    printer.setMessage("电梯限载10人");
    gotoxy(x, y++);
    cout << (up ? "电梯上行" : "电梯下行") << " 限载10人";
    Printer::printDevisionLine(x, y);
    gotoxy(x, y);
    cout << "请输入使用电梯的人数：";
    showCursor(); enableEcho();
    int num; cin >> num;
    hideCursor(); disableEcho();
    Printer::clearLine(x, y, false);
    for(int i = 1; i <= num; i++) {
        gotoxy(x, y);
        cout << "请输入当前乘客的需前往的楼层：";
        gotoxy(x, y + 1);
        cout << std::format("当前选择的乘客({}/{})", i, num);
        gotoxy(x + 30, y);
        showCursor(); enableEcho();
        int floor; cin >> floor;
        hideCursor(); disableEcho();
        Printer::clearLine(x + 30, y, 5, false);
        Printer::clearLine(x, y + 1);
        gotoxy(x, y + 1);
        if(!checkFloor(elevator, logger, printer, floor, up)) {
            mySleep(1500); i--;
            Printer::clearLine(x, y + 1);
            continue;
        }
        elevator.addPerson(i, floor);
    }

}

bool checkFloor(AdvElevator &elevator, Logger &logger, Printer &printer, int targetFloor, bool up) {
    bool down = !up;
    if(targetFloor < 1) {
        logger.error(std::format("用户{}输入的目标楼层超出最小范围", elevator.getPersonNum() + 1));
        cout << "暂时没有建设地下城的打算呢！";
        return false;
    }
    if(targetFloor > FLOOR) {
        logger.error(std::format("用户{}输入的目标楼层超出最大范围", elevator.getPersonNum() + 1));
        cout << "暂时没有建设空岛的打算呢！";
        return false;
    }
    if(targetFloor == elevator.getCurrentFloor()) {
        logger.error(std::format("用户{}输入的目标楼层与当前楼层相同", elevator.getPersonNum() + 1));
        cout << std::format("用户{}已抵达目标楼层，用时0s！", elevator.getPersonNum() + 1);
        return false;
    }
    if(up && targetFloor < elevator.getCurrentFloor()) {
        logger.error("电梯需要向上行驶！");
        cout << "电梯需要向上行驶！";
        return false;
    }
    if(down && targetFloor > elevator.getCurrentFloor()) {
        logger.error("电梯需要向下行驶！");
        cout << "电梯需要向下行驶！";
        return false;
    }
    return true;
}

void elevatorUp(AdvElevator &elevator, Logger &logger, Printer &printer) {
    elevatorUpDown(elevator, logger, printer, true);
}

void elevatorDown(AdvElevator &elevator, Logger &logger, Printer &printer) {
    elevatorUpDown(elevator, logger, printer, false);
}

void elevatorUpDown(AdvElevator &elevator, Logger &logger, Printer &printer, bool up) {
    bool down = !up;
    if(up && elevator.getCurrentFloor() == FLOOR) {
        logger.error("用户在顶层尝试上行！");
        printer.setMessage("上面的区域以后再来探索吧！");
        return;
    }
    if(down && elevator.getCurrentFloor() == 1) {
        logger.error("用户在底层尝试下行！");
        printer.setMessage("暂时没有建设地下城的打算呢！");
        return;
    }

    getPersonInfo(elevator, logger, printer, true);
    up ? elevator.setUpButton() : elevator.setDownButton();
}

NAMESPACE_END