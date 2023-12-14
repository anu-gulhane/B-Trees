#include "Logger.hpp"
Logger::Logger()
{
    this->fout.open(this->logFile, ios::out);
}

void Logger::log(string logString)
{
    fout << logString << endl;
}
