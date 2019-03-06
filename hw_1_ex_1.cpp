#include <iostream> 
#include <string>
using namespace std;

main() {

	string name1 = "Rosencrantz";
	string name2 = "Guildenstern";
	string message = "Safe travels, ";

	cout << message << name1 << " and " << name2 << "!" << endl;

	int travelers = 3;

	cout << "Make certain to pack enough supplies for " << travelers << " people!" << endl;
	
	return 0;
}