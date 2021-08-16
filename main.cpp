#include <memory>
#include <loglib.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

int main() {
    auto a = std::make_shared<Logs>("path");
    auto current_path = std::make_unique<std::filesystem::path>(std::filesystem::current_path());
    std::string path = current_path->string();
    char slash = 0x5C;
    path += slash;
    path += "test.txt";
    std::cout << path << std::endl;
    std::ofstream out;
    out.open(path);
    out << "Hello, logs";
    out.close();
    return 0;
}
