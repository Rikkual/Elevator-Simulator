//
// Created by Rikkual on 2024/5/3.
//

#include <bits/stdc++.h>
#include "Elevator.h"
#include "Logger.h"
#include "Printer.h"
#include "TerminalControl.h"

#include "config.h"

NAMESPACE_SOLVE_ELEVAOTR

std::vector<string> options = {
        "电梯上行",
        "电梯下行",
        "打开日志",
        "退出程序"
};

bool executeOption(Elevator &elevator, Logger &logger, Printer &printer, int choice);
void elevatorUp(Elevator &elevator, Logger &logger, Printer &printer);
void elevatorDown(Elevator &elevator, Logger &logger, Printer &printer);
void elevatorUpDown(Elevator &elevator, Logger &logger, Printer &printer, bool up);

void solve(Elevator &elevator, Logger &logger, Printer &printer) {
    int stx = INTERACT_X, sty = INTERACT_Y;
    printer.setMessage(std::format("Ciallo, 本电梯最高服务至{}层。", FLOOR));
    while(true) {
        int x = stx, y = sty;
        printer.printOptions(x, y, options);
        showCursor(); enableEcho();
        getCursorPos(x, y);

        int choice; cin >> choice;
        hideCursor(); disableEcho();
        Printer::clearAbout();

        if(!executeOption(elevator, logger, printer, choice)) break;
    }
}

bool executeOption(Elevator &elevator, Logger &logger, Printer &printer, int choice) {
    hideCursor(); disableEcho();
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

void elevatorUp(Elevator &elevator, Logger &logger, Printer &printer) {
    elevatorUpDown(elevator, logger, printer, true);
}

void elevatorDown(Elevator &elevator, Logger &logger, Printer &printer) {
    elevatorUpDown(elevator, logger, printer, false);
}

void elevatorUpDown(Elevator &elevator, Logger &logger, Printer &printer, bool up) {
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

    int x = INTERACT_X, y = INTERACT_Y;
    gotoxy(x, y);
    Printer::printDevisionLine(x, y);

    gotoxy(x, y++);
    cout << "          " << (up ? "电梯上行" : "电梯下行");
    if(COUT_ANIMATION) mySleep(ANIMATION_SPEED);

    Printer::printDevisionLine(x, y);

    while(true) {
        gotoxy(x, y);
        cout << "请输入目标楼层：";
        showCursor(); enableEcho();
        int cursorX, cursorY;
        getCursorPos(cursorX, cursorY);
        int targetFloor; cin >> targetFloor;
        Printer::clearLine(cursorX, cursorY);
        hideCursor(); disableEcho();

        if(targetFloor < 1) {
            Printer::clearLine(x, y + 1);
            gotoxy(x, y + 1);
            logger.error("目标楼层超出最小范围");
            cout << "暂时没有建设地下城的打算呢！";
            continue;
        }
        if(targetFloor > FLOOR) {
            Printer::clearLine(x, y + 1);
            gotoxy(x, y + 1);
            logger.error("目标楼层超出最大范围");
            cout << "暂时没有建设空岛的打算呢！";
            continue;
        }
        if(targetFloor == elevator.getCurrentFloor()) {
            Printer::clearLine(x, y + 1);
            gotoxy(x, y + 1);
            logger.error(std::format("电梯{}的目标楼层与当前楼层相同", (up ? "上行" : "下行")));
            cout << "你已抵达目标楼层，用时0s！";
            continue;
        }
        if(up && targetFloor < elevator.getCurrentFloor()) {
            Printer::clearLine(x, y + 1);
            gotoxy(x, y + 1);
            logger.error("电梯需要向上行驶！");
            cout << "电梯需要向上行驶！";
            continue;
        }
        if(down && targetFloor > elevator.getCurrentFloor()) {
            Printer::clearLine(x, y + 1);
            gotoxy(x, y + 1);
            logger.error("电梯需要向下行驶！");
            cout << "电梯需要向下行驶！";
            continue;
        }

        Printer::clearAbout(y + 1);
        up ? elevator.setUpButton(targetFloor) : elevator.setDownButton(targetFloor);
        printer.setMessage(std::format("电梯已抵达{}层。", targetFloor));
        break;
    }
}

NAMESPACE_END