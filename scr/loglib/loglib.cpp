#include "loglib.hpp"
#include <utility>

[[maybe_unused]] Logs::Logs(const std::string& path) {
    this->_path = path;  // Запись пути к файламам логов
}

[[maybe_unused]] Logs::Logs(Logs &test) {
    this->_path = test.get_path();  // Копировнаие пути
}

[[maybe_unused]] void Logs::set_path(std::string path) {
    this->_path = std::move(path);
}

std::string Logs::get_path() {
    return this->_path;
}



