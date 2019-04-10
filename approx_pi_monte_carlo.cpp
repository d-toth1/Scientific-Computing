// Monte Carlo simulation to approximate pi

#include <iostream>
#include <random>
#include <functional>

using namespace std;

int main(int argc, char* argv[]) {

    int seed_value;
    random_device rd;

    if (argc == 1) {
        seed_value = rd();
    } else {
        seed_value = stoi(argv[1]);
    }

    mt19937 generator(seed_value);

    uniform_real_distribution<double> distribution(-1.0, 1.0);

    auto draw = bind(distribution, ref(generator));

    int num_trials;
    cout << "Enter the number of trials: ";
    cin >> num_trials;

    int total = 0;

    double x;
    double y;

    for (int i = 0; i < num_trials; i++) {
        x = draw();
        y = draw();

        if (pow(x, 2) + pow(y, 2) <= 1) {
            total += 1;
        }
    }

    cout << "Approximation: " << 4 * double(total)/double(num_trials) << endl;

    return 0;
}
