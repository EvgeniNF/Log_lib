#include "loglib.hpp"

void log::Logger::add_message(log::category c, const std::string& mess) {
    log::Logger::list_mess.push_back(std::move(Message(c, mess)));
}

void log::Logger::show() {
    for (const auto &i : log::Logger::list_mess){
        auto in_time_t = std::chrono::system_clock::to_time_t(i.time);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
        std::cout << "-- @Time : " << ss.str();
        std::cout << " @Num thread : " << i.num_thr;
        std::cout << " ";
        switch (i.c_t) {
            case category::ALARM:
                clutil::setColor(clutil::BLACK);
                clutil::setBackgroundColor(clutil::RED);
                std::cout << "ALARM";
                break;
            case category::WARNING:
                clutil::setColor(clutil::BLACK);
                clutil::setBackgroundColor(clutil::YELLOW);
                std::cout << "WARNING";
                break;
            case category::INFO:
                clutil::setColor(clutil::BLACK);
                clutil::setBackgroundColor(clutil::GREEN);
                std::cout << "INFO";
                break;
        }
        clutil::resetColor();
        std::cout << " @Message: " << i.mes << std::endl;
    }
}

