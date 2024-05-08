# Elevator-Simulator
2024 C++ Experiment by Rikkual

本项目是Rikkual在zstu C++课程的课程实验，供学习参考使用。

## 版本更新

### v1.0.0

- 单人电梯初始版本提交

### v1.0.2

- 完成多人电梯的框架搭建
- 将各种命令行输出分离到Printer类，增加了代码的可读性
- 并优化了调试模式，增加了多种调试开关

### v1.0.3 

- 多人电梯整体实现完成
- 优化了AdvElevator的继承关系

- 对选项输入加入了错误判断，防止SmallC恶意输入非法字符导致cin产生cin std::_S_failbit的错误，造成cin失效，导致程序死循环
