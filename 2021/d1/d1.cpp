#include <iostream>
#include <string>
#include <optional>

int main() 
{
    std::string line;
    std::optional<int> last_value;
    size_t larger_count = 0;

    while(std::getline(std::cin, line)) {
        auto val = stoi(line);
        if (!last_value) {
            last_value = val;
            continue;
        }

        if (val > last_value) {
            larger_count++;
        }

        last_value = val;
    }

    std::cout << "`" << larger_count << "`" << std::endl;
    return 0;
}