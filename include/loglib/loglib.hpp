#ifndef LOGS_LIB_LOGLIB_HPP
#define LOGS_LIB_LOGLIB_HPP

#include "clutil.hpp"
#include <iostream>
#include <string>
#include <chrono>
#include <list>
#include <thread>
#include <mutex>
#include <sstream>
#include <memory>
#include <utility>
#include <iomanip>

namespace log{
// Category massage
enum struct category{
    INFO = 0,
    WARNING = 10,
    ALARM = 30
};

/*
 * Struct massage
 */
struct Message{
    Message(category c, std::string mess) : c_t(c), mes(std::move(mess)) {
        auto ss = std::make_unique<std::stringstream>();
        *(ss) << std::this_thread::get_id();
        time = std::chrono::system_clock::now();
        num_thr = ss->str();
    };
    std::chrono::time_point<std::chrono::system_clock> time{};
    std::string num_thr{};
    category c_t{};
    std::string mes{};
};

/*
 * Class Logger
 */
class Logger{
public:
    static void add_message(category c, const std::string& mess);
    static void show();
private:
    static std::mutex mt_buff;
    static std::list<Message> list_mess;
};

}

#endif //LOGS_LIB_LOGLIB_HPP
