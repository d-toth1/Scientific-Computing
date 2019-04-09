#include <iostream>
#include <vector>
using namespace std;

bool Prime(int a);
int Totient_Sum(const vector<int> &a, const int &b);

int main() {

    int N;
    vector<int> primes;
    cout << "Enter an integer: ";
    cin >> N;
    for (int i = 2; i <= N; i++) {
        if (Prime(i)) {
            primes.push_back(i);
        }
    }
    cout << "The totient sum up to " << N << " is: " << Totient_Sum(primes, N) << endl;
    return 0;
}

bool Prime(int a) {
    bool isPrime = true;
    for (int i = 2; i < a; i++) {
        if (a % i == 0) {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

int Totient_Sum(const vector<int> &a, const int &b) {
    int total = 1.0;
    for (int i = 0; i < a.size(); i++) {
        if (b % a[i] != 0) {
            total += a[i];
        }
    }
    return total;
}
