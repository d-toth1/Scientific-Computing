#include <iostream>
using namespace std;

int main() {
		int n, result = 0;
		cout << "Please enter an positive integer: ";
		cin >> n;
		while (n<0) {
				cout << n << " is a negative integer. Please enter a positive integer: ";
				cin >> n;
		}
		for (int i = 1; i <= n; i++) {
				if (bool (i%2 == 0) !=  bool (i%5 == 0) ) {
						result += i;
				}
		}
		cout << "The sum of the integers from 1 to " << n << " that are divisible "
				"by 2 or 5 but not both is: " << result;
		return 0;
}
