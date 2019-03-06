#include <iostream>

using namespace std;

double Combination (int a, int b);

int main () {
    for (int n = 1; n <= 10; n++) {
        for (int k = 0; k <= n; k++) {
            cout << "For n = " << n << " and k = " << k << ", n choose k is: " << Combination(n,k) << endl;
        }
    }
    return 0;
}

double Combination (int a, int b) {
    double n_factorial = 1.0;
    double k_factorial = 1.0;
    double n_minus_k_factorial = 1.0;

    if ((a == 0) || (a == 1)) {
        n_factorial = 1.0;
    } else {
        for (int i = a; i > 1; i--) {
            n_factorial *= i;
        }
    }

    if ((b == 0) || (b == 1)) {
        k_factorial = 1.0;
    } else {
        for (int i = b; i > 1; i--) {
            k_factorial *= i;
        }
    }

    if (((a-b) == 0) || ((a-b) == 1)) {
        n_minus_k_factorial = 1.0;
    } else {
        for (int i = (a-b); i > 1; i--) {
            n_minus_k_factorial *= i;
        }
    }

    return (n_factorial/(k_factorial*n_minus_k_factorial));
}
