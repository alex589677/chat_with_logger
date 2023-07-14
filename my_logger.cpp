#include <chrono>
#include "my_logger.h"

Logger::Logger() {
    // дописываем в файл
    outStream.open("log.txt", std::ios::app);
    if (!outStream.is_open()) {
        std::cout << "Error open stream outStream as file 'log.txt'\n";
    }
}

void Logger::writeFile(std::string str) {
    shared_mutex.lock();

    time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    char timestamp[26];
    ctime_s(timestamp, sizeof timestamp, &now);
    std::string timestampWithoutEndl(timestamp);
    timestampWithoutEndl = timestampWithoutEndl.substr(0, 24);

    std::string result = "";
    result = '\n' + timestampWithoutEndl + ": " + str;
    if (outStream.is_open()) {
        outStream << result;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    outStream.close();
}

void Logger::last_line() {
    shared_mutex.lock_shared();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::ifstream readStream("log.txt");
    if (!readStream.is_open())
        throw std::exception();
    std::string last_str = "";
    std::string buf;
    while (std::getline(readStream, buf, '\n')) {
        last_str = buf;
    }
    // color console begin
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, Green);
    // set color console green
    std::cout << last_str << std::endl;
    // set color console back white
    SetConsoleTextAttribute(hConsole, White);
    readStream.close();
    shared_mutex.unlock_shared();
}
