//
// Created by Rikkual on 2024/4/14.
//

#include "Logger.h"
#include <filesystem>

#include "config.h"

namespace fs = std::filesystem;

string formatTime(const tm* timeInfo, const string& format) {
    stringstream ss;
    ss << std::put_time(timeInfo, format.c_str());
    return ss.str();
}

tm *Logger::getLocalTime() {
    time_t currentTime = time(nullptr);
    tm *localTime = localtime(&currentTime);
    return localTime;
}

void Logger::deleteLogs() {
    try {
        string path = "log";
        fs::remove_all(path);
    #ifdef DEBUG_MODE
        debug("Log files deleted");
    #endif
    }
    catch(const fs::filesystem_error& e) {
        error("Failed to delete log files: " + string(e.what()));
    }
}

void Logger::creatPath() {
    string dir = "log";
    // CreateDirectory(dir.c_str(), nullptr);
    fs::create_directory(dir.c_str());
}

Logger::Logger(): Logger(formatTime(getLocalTime(), "%Y-%m-%d_%H%M%S")) {
    // string timeString = formatTime(getLocalTime(), "%Y-%m-%d %H:%M:%S");
}

Logger::Logger(const string &fileName) {
    if(CLEAR_LOG_FILE) deleteLogs();
    creatPath();
    logFileName = fileName;
    if(logFileName.substr(logFileName.size() - 4) != ".log")
        logFileName += ".log";
    logFile = ofstream("log/" + logFileName);
#ifdef DEBUG_MODE
    debug("Debug mode enabled");
    debug("Logger created");
    debug("Log file: " + logFileName);
    // open();
#endif
}

Logger::~Logger() {
#ifdef DEBUG_MODE
    debug("Logger destroyed");
#endif
    if(logFile.is_open()) {
        logFile.close();
    }
}

void Logger::open() {
    info("log file opened");
    system(("notepad log/" + logFileName).c_str());
}

void Logger::info(const string &message) {
    if(LOG_TIME) logFile << formatTime(getLocalTime(), "%Y-%m-%d %H:%M:%S") << " [INFO] ";
    logFile << message << endl;
}

void Logger::error(const string &message) {
    if(LOG_TIME) logFile << formatTime(getLocalTime(), "%Y-%m-%d %H:%M:%S") << " [ERROR] ";
    logFile << message << endl;
}

void Logger::debug(const string &message) {
    if(LOG_TIME) logFile << formatTime(getLocalTime(), "%Y-%m-%d %H:%M:%S") << " [DEBUG] ";
    logFile << message << endl;
}