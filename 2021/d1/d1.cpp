#include <iostream>
#include <string>
#include <optional>
#include <deque>
#include <algorithm>

static int part_one() 
{
    std::string line;
    std::optional<int> last_value;
    size_t increasing = 0;

    while(std::getline(std::cin, line)) {
        auto val = stoi(line);
        if (!last_value) {
            last_value = val;
            continue;
        }

        if (val > last_value) {
            increasing++;
        }

        last_value = val;
    }

    return increasing;
}

static int part_two()
{
    std::string line;
    std::deque<int> window;
    int total = 0;
    int last_total;
    int increasing = 0;

    while(std::getline(std::cin, line)) {
        auto val = stoi(line);

        if (window.size() != 3 ) {
            window.push_front(val);
            total += val;
            continue;
        }

        last_total = total;
        total += val;
        total -= window.front();
        window.pop_front();
        window.push_back(val);

        if (total > last_total) {
            increasing++;
        }
    }

    return increasing;
}

int main() 
{
    std::cout << "`" << part_two() << "`" << std::endl;
    return 0;
}
