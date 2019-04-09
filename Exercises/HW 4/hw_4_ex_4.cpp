#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

bool Prime(int a);
double Brun_Estimator(const vector<int> &a);

int main() {
    int N;
    double total = 0.0;
    vector<int> primes;
    cout << "Enter an integer: ";
    cin >> N;
    for (int i = 3; i <= N; i++) {
        if (Prime(i) && (Prime(i-2) || (Prime(i+2)))) {
            primes.push_back(i);
        }
    }
    // Add function
    cout << "Estimation: " << setprecision(12) << fixed << Brun_Estimator(primes) << endl;
    return 0;
}

bool Prime (int a) {
    bool isPrime = true;
    for (int i = 2; i < a; i++) {
        if (a % i == 0) {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

double Brun_Estimator(const vector<int> &a) {
    double total = 0.0;
    for (int i = 0; i < a.size(); i++) {
        if (Prime(a[i] + 2)) {
            total += ( (1.0/a[i]) + (1.0/(a[i] + 2.0)));
        }
    }
    return total;
}
