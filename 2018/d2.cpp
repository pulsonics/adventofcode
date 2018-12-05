#include <iostream>
#include <string>
#include <sstream>
#include <vector>
 
using namespace std;
 
pair<bool, bool> getRepeatPair(string line)
{
	vector<int> table;
	table.resize(26, 0);
	
	int twoVal = 0;
	int threeVal = 0;
	
	for (char c : line)
	{
        int val = ++table[static_cast<int>(c) - 97];
        // Hard coded cases
        switch (val)
        {
        case 2:
        	twoVal++;
        	break;
        case 3:
            twoVal--;
            threeVal++;
            break;
        case 4:
            threeVal--;
            break;
        default:
            break;
        }
	}

    return {twoVal > 0, threeVal > 0};
}
 
int main() 
{
    string line;
    int twoVal = 0;
    int threeVal = 0;
    while(getline(cin, line))
    {
    	pair<bool, bool> rVal = getRepeatPair(line);
    	if (rVal.first) twoVal++;
    	if (rVal.second) threeVal++;
    }

    cout << twoVal * threeVal;

    return 0;
}
