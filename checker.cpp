#include <bits/stdc++.h>
#include <stdlib.h>

int main() {
    std::string rand_name = "2";
    std::string check_name = "3";
    std::string code_name = "4";
    system(std::format("g++ -O2 {}.cpp -o {}.exe", rand_name, rand_name).c_str());
    system(std::format("g++ -O2 {}.cpp -o {}.exe", check_name, check_name).c_str());
    system(std::format("g++ -O2 {}.cpp -o {}.exe", code_name, code_name).c_str());
    system(std::format("{}.exe > in.txt", rand_name).c_str());
    system(std::format("{}.exe < in.txt > {}.txt", check_name, check_name).c_str());
    system(std::format("{}.exe < in.txt > {}.txt", code_name, code_name).c_str());
    system(std::format("fc {}.txt {}.txt", code_name, check_name).c_str());
    system(std::format("del {}.exe {}.exe {}.exe {}.txt {}.txt {}.txt", rand_name, check_name, code_name, "in", check_name, code_name).c_str());
}