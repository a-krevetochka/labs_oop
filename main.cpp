#include "brackets.h"
#include <stdexcept>

using namespace std;

bool isOrderOfTheBracketsCorrect(string inputString);

int main()
{	
	string inputString;
	cin >> inputString;
	try {
		bool result = isOrderOfTheBracketsCorrect(inputString);
		cout << boolalpha << result << endl;
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
		return 0;
	}
	return 0;
}