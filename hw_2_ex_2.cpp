#include <iostream>
#include <iomanip>
using namespace std;

int main () {
		// Define variables for prices and counts
		double apple_price = 1.25;
		double banana_price = 2.25;
		double orange_price = 1.00;
		double lemon_price = 1.75;
		int apple_count, banana_count, orange_count, lemon_count;

		// Apples
		cout << "Please enter the number of apples: ";
		cin >> apple_count;
		while (apple_count < 0) {
				cout << "Please enter a positive integer value: ";
				cin >> apple_count;
		}
		if (apple_count > 1) {
						cout << "The bill for " << apple_count << " apples is: $" << setprecision(2) << fixed << apple_count*apple_price << ".\n";
		}   else if (apple_count == 1) {
						cout << "The bill for " << apple_count << "is: $" << setprecision(2) << fixed << apple_count*apple_price << ".\n";
		}   else {
						cout << "The bill for 0 apples is $0.00.\n";
		}
		// Bananas
		cout << "Please enter the number of bunches of bananas: ";
		cin >> banana_count;
		while (banana_count < 0) {
				cout << "Please enter a positiver integer value: ";
				cin >> banana_count;
		}
		if (banana_count > 1) {
				cout << "The bill for " << banana_count << " bunches of bananas is: $" << setprecision(2) << fixed << banana_count*banana_price << ".\n";
		} else if (banana_count == 1) {
				cout << "The bill for " << banana_count << " bunch of bananas is: $" << setprecision(2) << fixed << banana_price << ".\n";
		} else {
				cout << "The bill for 0 bunches of bananas is $0.00.\n";
		}
		// Oranges
		cout << "Please enter the number of oranges: ";
		cin >> orange_count;
		while (orange_count < 0) {
				cout << "Please enter a positiver integer value: ";
				cin >> orange_count;
		}
		if (orange_count > 1) {
				cout << "The bill for " << orange_count << " oranges is: $" << setprecision(2) << fixed << orange_count * orange_price << ".\n";
		} else if (orange_count == 1) {
				cout << "The bill for " << orange_count << " orange is: $" << setprecision(2) << fixed << orange_price << ".\n";
		} else {
				cout << "The bill for 0 oranges is $0.00.\n";
		}
		// Lemons
		cout << "Please enter the number of lemons: ";
		cin >> lemon_count;
		while (lemon_count < 0) {
				cout << "Please enter a positiver integer value: ";
				cin >> lemon_count;
		}
		if (lemon_count > 1) {
				cout << "The bill for " << lemon_count << " lemons is: $" << setprecision(2) << fixed << lemon_count * lemon_price << ".\n";
		} else if (lemon_count == 1) {
				cout << "The bill for " << lemon_count << " lemon is: $" << setprecision(2) << fixed << lemon_price << ".\n";
		} else {
				cout << "The bill for no 0 lemons is $0.00.\n";
		}
		cout << "\n";
		double total_bill = (apple_count*apple_price) + (banana_count*banana_price) + (orange_count*orange_price) + (lemon_count*lemon_price);
		cout << "The total number of items purchased is: " << apple_count + banana_count + orange_count + lemon_count << ".\n";
		cout << "The total bill is: $" << setprecision(2) << fixed << total_bill << ".\n";

		return 0;

}
