#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <functional>

using namespace std;

double dist_to_origin(vector<int> v);

int main(int argc, char* argv[]) {

    if (argc < 4) {
        cout << "Enter all command line arguments." << endl;
        return 0;
    }

    int d = stoi(argv[1]);
    int k = stoi(argv[2]);
    int n = stoi(argv[3]);

    int seed_value;
    random_device rd;
    seed_value = rd();
    mt19937 generator(seed_value);

    bernoulli_distribution forw_back_dist(.5);
    uniform_int_distribution<int> direction_dist(0, d-1);

    auto forw_back_draw = bind(forw_back_dist, ref(generator));
    auto direction_draw = bind(direction_dist, ref(generator));

    double distances = 0.0;

    for(int i = 0; i < n; i++) {

        int steps = 0;
        int coord_choice;
        int forw_back_choice;
        vector<int> position(d, 0);

        while(steps < k) {

            coord_choice = direction_draw();
            forw_back_choice = 2 * forw_back_draw() - 1;
            position[coord_choice] += 1*forw_back_choice;
            steps ++;
        }
        distances += dist_to_origin(position);
    }

    cout << "Approximation: " << distances/double(n) << endl;

    return 0;
}

double dist_to_origin(vector<int> v) {

    double sum = 0.0;
    for(int i = 0; i < v.size(); i++) {
        sum += pow(v[i], 2);
    }
    return pow(sum, 0.5);
}
