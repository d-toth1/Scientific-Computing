#include <iostream>
#include <random>
#include <functional>
#include "hw_6_ex_2_f.cpp"

using namespace std;

int main(int argc, char* argv[]) {

    if (argc < 2) {
        cout << "No command line arguments entered." << endl;
        return 0;
    }

    double a, b, samples;
    a = stod(argv[1]);
    b = stod(argv[2]);
    samples = stoi(argv[3]);

    int seed_value;
    random_device rd;
    seed_value = rd();
    mt19937 generator(seed_value);
    uniform_real_distribution<double> distribution(a, b);
    auto draw = bind(distribution, ref(generator));

    double x;
    double total = 0.0;
    for (int i = 0; i < samples; i++) {
        x = draw();
        total += f(x);
    }
    cout << "Approximation: " << ((b-a)/double(samples))*total << endl;
    return 0;
}
