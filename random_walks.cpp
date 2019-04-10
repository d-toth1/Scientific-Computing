// One-dimensional random walk

#include <random>
#include <iostream>
#include <functional>

using namespace std;

int main(int argc, char* argv[]) {

    if (argc == 1) {
        cout << "Please enter the final position and number of trials!" << endl;
        return 0;
    }

    int M = stoi(argv[1]);
    long long int num_trials = stoll(argv[2]);

    int seed_value;
    random_device rd;
    seed_value = rd();

    mt19937 generator(seed_value);

    bernoulli_distribution distribution(.5);

    auto draw = bind(distribution, ref(generator));

    long long int total_moves_trials = 0;

    for (long long int i = 0; i < num_trials; i++) {
        int pos = 0;
        int steps = 0;

        while (pos != -M && pos != M) {
            pos += 2 * draw() - 1;
            steps += 1;
        }
        total_moves_trials += steps;
    }

    cout << "Approx. steps to reach distance of " << M << " from the origin: "
        << double(total_moves_trials)/double(num_trials) << endl;

    return 0;
}
