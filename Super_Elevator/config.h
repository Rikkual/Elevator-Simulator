//
// Created by Rikkual on 2024/4/14.
//

#ifndef CONFIG_FILE
#define CONFIG_FILE

#define VERSION "1.0.1"                // 版本号

#define DEBUG_MODE 1                   // 调试模式开关，0为关闭，1为开启

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::stringstream;

extern const int FLOOR;                 // 电梯的总楼层数
extern const int INIT_FLOOR;            // 电梯的起始楼层

extern const bool COUT_ANIMATION;       // 是否在控制台输出动画效果
extern const int ANIMATION_SPEED;       // 动画速度，单位为毫秒
extern const int DELETE_LINE_LENGTH;    // 删除单行的最大长度
extern const int DEVISIONLINE_LENGTH;   // 分割线的长度

extern const int ABOUT_X;               // 关于菜单的X坐标
extern const int ABOUT_Y;               // 关于菜单的Y坐标
extern const int INTERACT_X;            // 交互菜单的X坐标
extern const int INTERACT_Y;            // 交互菜单的Y坐标

extern const int FLOOR_DISPLAY_X;       // 电梯楼层显示的X坐标
extern const int FLOOR_DISPLAY_Y;       // 电梯楼层显示的Y坐标
extern const int ELEVATOR_SPEED;        // 电梯运行的速度，单位为毫秒/层的单位时间
extern const int ELEVATOR_SPEED_CNT;    // 电梯运行的速度分级
extern const int DOOR_SPEED;            // 电梯门的速度，单位为毫秒/格

extern const bool CLEAR_LOG_FILE;       // 是否在启动前清空log文件
extern const bool LOG_TIME;             // 是否在log文件中记录时间

#define NAMESPACE_SOLVE_ELEVAOTR namespace SolveElevator {
#define NAMESPACE_SOLVE_ADVELEVAOTR namespace SolveAdvelevator {
#define NAMESPACE_END }

#endif // CONFIG_FILE