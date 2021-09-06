#ifndef LOGS_LIB_LOGLIB_HPP
#define LOGS_LIB_LOGLIB_HPP

#include <iostream>
#include <string>
#include <chrono>

namespace log{

// Category massage
enum struct category{
    INFO = 0,
    WARNING = 10,
    ERROR = 20,
    ALARM = 30
};

/*
 * Struct massage
 */
struct Massage{
    std::chrono::local_t time{};
    unsigned int num_thr{};
    category c_t{};
    std::string massage{};
};

/*
 * Class buffer
 */
class Buffer{
public:

private:

};

}

#endif //LOGS_LIB_LOGLIB_HPP
