#include "loglib.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <fstream>
#include <filesystem>
#include <algorithm>

[[maybe_unused]] Logs::Logs() {
    this->_separator = static_cast<char>(std::filesystem::path::preferred_separator); // Установка файлового разделителя
    this->_current_path = this->find_path();                                          // Установка корневого пути
}

[[maybe_unused]] Logs::Logs(const std::string& dir) {
    this->_separator = static_cast<char>(std::filesystem::path::preferred_separator); // Установка файлового разделителя
    this->_current_path = this->find_path();                                          // Установка корневого пути
    this->set_path(std::move(dir));
}

[[maybe_unused]] Logs::Logs(Logs &test) {
    this->_path = test.get_path();  // Копировнаие пути
}

[[maybe_unused]] void Logs::set_path(const std::string& dir) {
    std::cout << "-- Current path: " << this->_current_path << std::endl;
    std::cout << "-- Check path:" << std::endl;
    this->_path = this->_current_path;
    this->_path.push_back(this->_separator);
    this->_path += dir;
    if(!(std::filesystem::exists(this->_path))){
        std::cout << "-- -- Directory: " << this->_path << " was not found!" << std::endl;
        std::cout << "-- -- Create new directory: " << this->_path << std::endl;
        if(std::filesystem::create_directory(this->_path)){
            std::cout << "-- -- New directory was created!" << std::endl;
        }
        else {
            std::cout << "-- -- Error! Not possible to create directory..." << std::endl;
        }
    }
    else {
        std::cout << "-- -- Directory is exist..." << std::endl;
        std::cout << "-- -- Files in directory " << this->_path << std::endl;
        unsigned int i = 0;
        for (const auto & entry: std::filesystem::directory_iterator(this->_path)){
            i++;
            std::cout << "        " << entry.path().string() << std::endl;
        }
        if (i == 0){
            std::cout << "        Directory has no any files!" << std::endl;
        }
    }
}

std::string Logs::get_path() {
    return this->_path;
}

std::string Logs::find_path(){
    return std::filesystem::current_path().string();
}

[[maybe_unused]] std::string Logs::get_current_path(){
    return this->_current_path;
}