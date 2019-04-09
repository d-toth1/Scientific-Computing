#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

double f(double x);
double f_prime(double x);

int main(int argc, char* argv[]) {

    double x = 0.0;
    double tol = 0.0000001;
    int max_iter = 20;

    ofstream ofs("hw_5_ex_3_output.dat");

    switch(argc) {
        case 4:
            x = stod(argv[1]);
            tol = stod(argv[2]);
            max_iter = stoi(argv[3]);
            break;
        case 3:
            x = stod(argv[1]);
            tol = stod(argv[2]);
            break;
        case 2:
            x = stod(argv[1]);
            break;
        default:
            break;
    }
    ofs << 0 << '\t' << setprecision(16) << fixed << x << '\n';

    if (f(x) == 0) {
        cout << "Cannot perform Newton's method." << endl;
        return 0;
    }
    double x1 = x;
    int i = 0;
    while (abs(f(x)) >= tol && i < max_iter) {
        if (f_prime(x) == 0) {
            cout << "Error: Division by 0." << endl;
            return 0;
        }
        x1 = x1 - (f(x1)/f_prime(x1));
        x = x1;
        i = i + 1;
        ofs << i << '\t' << setprecision(16) << fixed << x << '\n';
    }
    cout << "Root: " << setprecision(16) << fixed << x1 << endl;
    return 0;
}

double f(double x) {

    return pow(x, 5.0) - x + 1.0;
}

double f_prime(double x) {

    return (5.0 * pow(x, 4.0)) - 1.0;
}
