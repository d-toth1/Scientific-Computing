#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Please input integers a and b (separated by one space): ";
    cin >> a >> b;

    cout << "The sum of " << a << " and " << b << " is: " << a + b << endl;
    cout << "The difference of " << a << " and " <<  b << " is: " << a - b << endl;
    cout << "The product of " << a << " and " << b << " is: " << a*b << endl;
    
    return 0;
}