#include <memory>
#include <loglib.hpp>
#include <fstream>

int main() {
    auto a = std::make_shared<Logs>("path");
    std::string file = "test.txt";
    std::ofstream out;
    out.open(file);
    out << "Hello, logs";
    out.close();
    return 0;
}
