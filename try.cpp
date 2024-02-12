#include <iostream>
#include <vector>
int main() {
    std::cout << "123" << std::endl;
    std::vector<int> v = {1 ,2,3};
    for(auto i:v) {
        std::cout << i;
    }
    return 0;
}