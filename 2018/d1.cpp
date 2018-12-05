#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>
 
using namespace std;
 
int main() {
    std::string line;
    bool repeat = true;
    set<int> lookup;
    int curFreq = 0;
    int curVal = 0;
 
    vector<int> data;
    std::pair<std::set<int>::iterator, bool> rVal = lookup.insert(0);
    int index = 0;
 
    while (repeat)
    {
    	if(std::getline(std::cin, line))
    	{
    		curVal = std::stoi(line, nullptr);
    		data.push_back(curVal);
    	}
    	else
    	{
    		curVal = data[index % data.size()];
    		index++;
    	}
 
        curFreq += curVal;
 
        rVal = lookup.insert(curFreq);
        repeat = rVal.second;
    }
 
    cout << curFreq;
    return 0;
}
