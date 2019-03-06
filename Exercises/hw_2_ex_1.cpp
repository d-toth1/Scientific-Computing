#include <iostream>
using namespace std;

int main() {

		int a;
		int b;
		int c;

		cout << "Please enter the first integer: ";
		cin >> a;

		cout << "Please enter the second integer: ";
		cin >> b;

		cout << "Please enter the third integer: ";
		cin >> c;

		cout << "\n";
		if (a != b && b != c) {
			cout << "The values of the integers, in increasing order, are: ";
		}

		if (a<b && b<c) {
				cout << a << " " << b << " " << c;
		} else if (a<c && c<b) {
				cout << a << " " << c << " " << b;
		} else if (b<a && a<c) {
				cout << b << " " << a << " " << c;
		} else if (b<c && c<a) {
				cout << b << " " << c << " " << a;
		} else if (c<a && a<b) {
				cout << c << " " << a << " " << b;
		} else if (c<b && b<a) {
				cout << c << " " << b << " " << a;
		} else {
			cout << "At least two of the variables are equal." << endl;
		}
		return 0;
}
