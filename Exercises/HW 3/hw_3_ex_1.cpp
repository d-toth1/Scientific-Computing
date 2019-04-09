#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main () {
    vector<string> int_to_month {"January", "February", "March", "April", "May",
        "June", "July", "August", "September", "October", "November", "December"};
    int month;
    int day;
    int year;

    cout << "Enter an integer for the month: ";
    cin >> month;
    cout << "Enter an integer for the day: ";
    cin >> day;
    cout << "Enter an integer for the year: ";
    cin >> year;

    cout << int_to_month[month-1] << " " << day << ", " << year << "." << endl;

    return 0;
}
