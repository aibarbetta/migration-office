#include "Logger.h"

#include <unistd.h>

const static std::string LOGGER_LOCK_FILE = "/tmp/logger_lock";

Logger::Logger(const bool debug, const std::string& file) : file(file), lock(LOGGER_LOCK_FILE) {
    if (!debug) this->file = "/dev/null";
}

Logger& Logger::operator<<(io_manip_ptr_t f) {
    if (f == (io_manip_ptr_t)&std::endl) {
        oss << std::endl;
        lock.lock();
        int fd = open(file.c_str(), O_WRONLY | O_CREAT, 0666);
        ssize_t bytes_written = write(fd, oss.str().c_str(), oss.str().size());
        if ((unsigned long) bytes_written != oss.str().size()) {
            close(fd);
            lock.unlock();
            oss.str("");
            throw std::system_error(errno, std::system_category(), "Error in write: could not write Logger file.");
        }
        close(fd);
        lock.unlock();
        oss.str("");
    }
    return *this;
}