#include <memory>
#include <loglib.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>


int main() {
    auto a = std::make_shared<Logs>("logs");
    return 0;
}

/*
    auto current_path = std::make_unique<std::filesystem::path>(std::filesystem::current_path());
    std::string path = current_path->string();
    const char slash = 0x5C;
    path += slash;
    path += "logs";
    path += slash;
    path += "test.txt";
    if (std::filesystem::exists(path)){
        std::cout << "File path " << path << " is exist!" << std::endl;
    }
    else {
        std::cout << "File path " << path << " is not exist!" << std::endl;
    }
    if (!(std::filesystem::exists(path))){
        if(std::filesystem::create_directory(path)){
            std::cout << "Created new directory: " << path << std::endl;
        }
        else {
            std::cout << "Error! directory was not created!" << std::endl;
        }
    }
    path += slash;
    path += "test.txt";
    std::cout << "Print in file: " << path << " - ";
    std::string text = "I am log file";
    std::cout << text << std::endl;
    std::ofstream out;
    out.open(path);
    out << text;
    out.close();
 */