#include <iostream>
#include <string>
#include <algorithm>

constexpr auto directions = {
    "forward",
    "down",
    "up"};

static void part_one() 
{
    std::string line;
    size_t increasing = 0;
    int value = 0;
    int depth = 0;
    int distance = 0;

    while (std::getline(std::cin, line))
    {
        auto split = line.find(" ");
        auto direction = std::find(directions.begin(), directions.end(), line.substr(0, split)) - directions.begin();
        auto value = stoi(line.substr(split, line.size()));
        switch (direction) {
            case 0:
                distance+= value; break;
            case 1: 
                depth += value; break;
            case 2: 
                depth -= value; break;
        }
    }

    std::cout << depth << " " << distance << " " << depth*distance << std::endl;
}

static void part_two() 
{
    std::string line;
    size_t increasing = 0;
    int value = 0;
    int depth = 0;
    int aim = 0;
    int distance = 0;

    while (std::getline(std::cin, line))
    {
        auto split = line.find(" ");
        auto direction = std::find(directions.begin(), directions.end(), line.substr(0, split)) - directions.begin();
        auto value = stoi(line.substr(split, line.size()));
        switch (direction) {
            case 0:
                distance+= value;
                depth += (aim * value);
                break;
            case 1: 
                aim += value; break;
            case 2: 
                aim -= value; break;
        }
    }

    std::cout << depth << " " << distance << " " << depth*distance << std::endl;
}

int main(void)
{
    part_two();
    return 0;
}