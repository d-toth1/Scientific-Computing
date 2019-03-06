#include <iostream>
using namespace std;

bool Prime (int a);

int main () {
    int N;
    cout << "Enter a positive integer: ";
    cin >> N;
    for (int i = 1; i <= N; i++) {
        if (Prime(i) == true) {
            cout << i << " is a prime number." << endl;
        } else {
            cout << i << " is not a prime number." << endl;
        }
    }
    return 0;
}

bool Prime (int a) {
    bool isPrime = true;
    if (a == 1) {
        isPrime = false;
    }
    for (int i = 2; i <= (a/2); i++) {
        if (a % i == 0) {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}
