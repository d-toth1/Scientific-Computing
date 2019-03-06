#include <iostream>
using namespace std;

int f (int n);

int main () {
    int N;
    double sum = 0.0;
    cout << "Enter an integer: ";
    cin >> N;
    for (int i = 1; i <= N; i++) {
        if (f(i) % 2 != 0) {
            sum += f(i);
        }
    }
    //cout << f(20) << endl;
    cout << "Sum: " << sum << endl;
    return 0;
}

int f (int n) {
    if (n <= 2) {
        return n*n;
    } else if ( (n % 2 == 0) && (n > 2)) {
        return 3*f(n/2) + 1;
    } else if ((n % 2 != 0) && (n > 1)) {
        return f((n+1)/2);
    }
    return 0;
}
