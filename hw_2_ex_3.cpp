#include <iostream>
using namespace std;

int main() {
		int n;
		int result = 0;
		cout << "Enter a positive integer: ";
		cin >> n;
		while (n<0) {
				cout << n << " is negative. Enter a positive integer: ";
				cin >> n;
		}
		for (int i = 1; i <= n; i++) {
				result += (i*i*i);
		}
		cout << "The sum of the cubes of 1 to " << n << " is: " << result << "\n";
		int new_result = ((n*(n+1))/2)*((n*(n+1))/2);
		cout << "Using a different formula, the sum of the cubes of 1 to " << n << " is: " << new_result;
		return 0;
}
