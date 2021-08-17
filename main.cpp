#include <memory>
#include <loglib.hpp>
#include <vector>


int main() {
    auto a = std::make_shared<Logs>("logs");
    std::vector<std::string> any = {"ab", "cd", "ef"};
    for (std::string &i : any){
        std::cout << i << std::endl;
    }
    return 0;
}
