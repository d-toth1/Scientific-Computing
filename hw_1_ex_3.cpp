#include <iostream>
using namespace std;

int main () {
    double apple_price = 1.25;
    double banana_price = 2.25;
    double orange_price = 1.00;
    double lemon_price = 1.75;
    int apple_count, banana_count, orange_count, lemon_count;

    cout << "Please enter the number of apples: ";
    cin >> apple_count; 
    cout << "The bill for " << apple_count << " apple(s) is: $" << apple_count*apple_price << ".\n";
    cout << "\n";
    cout << "Please enter the number of bunches of bananas: ";
    cin >> banana_count;
    cout << "The bill for " << banana_count << " bunch(es) of bananas is: $" << banana_count*banana_price << ".\n";
    cout << "\n";
    cout << "Please enter the number of oranges: ";
    cin >> orange_count;
    cout <<"The bill for " << orange_count << " orange(s) is: $" << orange_count*orange_price << ".\n";
    cout << "\n";
    cout << "Please enter the number of lemons: ";
    cin >> lemon_count;
    cout << "The bill for " << lemon_count << " lemon(s) is: $" << lemon_count*lemon_price << ".\n";
    cout << "\n";
    cout << "\n"; 

    double total_bill = (apple_count*apple_price) + (banana_count*banana_price) + (orange_count*orange_price) + (lemon_count*lemon_price);
    cout << "The total number of items purchased is: " << apple_count + banana_count + orange_count + lemon_count << ".\n";
    cout << "The total bill is: $" << total_bill << ".\n";
    
    return 0;


}
