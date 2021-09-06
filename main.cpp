#include <memory>
#include <loglib.hpp>
#include <vector>



int main() {
    std::cout << "Hello, logs!" << std::endl;
    log::Logger::add_message(log::category::ALARM, "Whats wrong!");
    log::Logger::add_message(log::category::ALARM, "Whats wrong!");
    log::Logger::add_message(log::category::ALARM, "Whats wrong!");
    log::Logger::add_message(log::category::WARNING, "AI AI AI AI AI!");
    log::Logger::add_message(log::category::WARNING, "AI AI AI AI AI!");
    log::Logger::add_message(log::category::WARNING, "AI AI AI AI AI!");
    log::Logger::add_message(log::category::WARNING, "AI AI AI AI AI!");
    log::Logger::add_message(log::category::WARNING, "AI AI AI AI AI!");
    log::Logger::add_message(log::category::ALARM, "Whats wrong!");
    log::Logger::add_message(log::category::INFO, "LOG OPERATION!");
    log::Logger::add_message(log::category::INFO, "LOG OPERATION!");
    log::Logger::add_message(log::category::INFO, "LOG OPERATION!");
    log::Logger::add_message(log::category::INFO, "LOG OPERATION!");
    log::Logger::show();
    return 0;
}
