#include "Logger.h"

#include <unistd.h>
#include <system_error>

const static std::string LOGGER_LOCK_FILE = "/tmp/logger_lock";

Logger::Logger(const std::string& file) : file(file), lock(LOGGER_LOCK_FILE) {}

Logger& Logger::operator<<(const std::string& message) {
    lock.lock();
    int fd = open(file.c_str(), O_WRONLY | O_CREAT, 0666);
    ssize_t bytes_written = write(fd, message.c_str(), message.size());
    if ((unsigned long) bytes_written != message.size()) {
        close(fd);
        lock.unlock();
        throw std::system_error(errno, std::system_category(), "Error in write: could not write Logger file.");
    }
    close(fd);
    lock.unlock();
    return *this;
}