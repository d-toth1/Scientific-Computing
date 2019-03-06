#include <iostream>
using namespace std;

int h (int n, int count);

int main () {
    int N;
    int sum = 0;
    cout << "Enter a positive integer: ";
    cin >> N;
    for (int i = 1; i <= N; i++) {
        sum += h(i, 0);
    }
    cout << sum;
    return 0;
}

int h (int n, int count) {
    count +=1;
    if (n == 2) {
        return count;
    } else if (n == 1) {
        count = 0;
        return count;
    } else if (n % 2 == 0) {
        return h(n/2, count);
    } else {
        return h(3*n + 1, count);
    }
}
