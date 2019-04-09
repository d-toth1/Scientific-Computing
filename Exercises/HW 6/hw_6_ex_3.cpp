#include <iostream>
#include <cmath>
#include <random>
#include <functional>

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
    uniform_real_distribution<double> distribution(-1.0, 1.0);
    auto draw = bind(distribution, ref(generator));

    double x, y;
    double total = 0.0;

    for (int i = 0; i < samples; i++) {
        x = draw();
        y = draw();
        while( !(pow(x, 2) + pow(y, 2) <= 1)) {
            x = draw();
            y = draw();
        }
        total += sqrt( pow((x-a), 2.0) + pow((y-b), 2.0) );
    }
    cout << "Approximation: " << total/double(samples) << endl;
    return 0;
}
