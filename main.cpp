#include <memory>
#include <loglib.hpp>
#include <vector>

struct Any{
    static int get_i() {
        return i;
    }
private:
    static const int i = 10;
};


int main() {
    std::cout << "Hello, logs!" << std::endl;
    std::cout << Any::get_i() << std::endl;
    return 0;
}
