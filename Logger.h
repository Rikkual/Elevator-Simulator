//
// Created by Rikkual on 2024/4/14.
//

#ifndef Logger_H
#define Logger_H


#include <bits/stdc++.h>
#include "config.h"

class Logger {
private:
    string logFileName;
    ofstream logFile;
public:
    void deleteLogs();
    static tm* getLocalTime();
    static void creatPath();
    Logger();
    explicit Logger(const string &fileName);
    ~Logger();
    void open();
    void info(const string &message);
    void error(const string &message);
    void debug(const string &message);
};


#endif //Logger_H
