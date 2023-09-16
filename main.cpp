#include "brackets.h"
#include <stdexcept>

using namespace std;

bool isOrderOfTheBracketsCorrect(string inputString);

int main()
{	
	string inputString;
	cin >> inputString;
    bool result = isOrderOfTheBracketsCorrect(inputString);
    cout << boolalpha << result << endl;
	return 0;
}