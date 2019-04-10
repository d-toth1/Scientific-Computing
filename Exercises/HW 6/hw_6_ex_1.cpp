#include <iostream>
#include <fstream>
#include <iomanip>
#include "hw_6_ex_1_f.h"

using namespace std;

int main(int argc, char* argv[]) {

    if (argc < 2) {
        cout << "No command line arguments entered." << endl;
        return 0;
    }

    double y_i_minus_one = stod(argv[1]);
    double b = stod(argv[2]);
    int N = stoi(argv[3]);
    string output_file = argv[4];

    ofstream ofs(output_file);

    double h = b/double(N);
    double x_i = 0.0;
    double y_i;
    for (int i = 0; i < N; i++) {
        y_i = y_i_minus_one + f(x_i, y_i)*h;
        y_i_minus_one = y_i;
        x_i = x_i + h;
        ofs << x_i << " " << y_i << '\n';
    }
    return 0;
}
