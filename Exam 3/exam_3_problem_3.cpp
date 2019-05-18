#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <functional>

using namespace std;

int main(int argc, char* argv[]){

    if (argc < 3){
        cout << "Enter both probability and number of trials." << endl;
        return 0;
    }

    double p = stod(argv[1]);
    int trials = stoi(argv[2]);

    ifstream ifs("coin_flip_pattern.txt");

    string pattern_str = "";

    char temp;
    while(ifs >> temp){
        pattern_str += temp;
    }

    cout << "Looking for pattern: " << pattern_str << endl;

    int seed_value;
    random_device rd;
    seed_value = rd();
    mt19937 generator(seed_value);
    bernoulli_distribution distribution(p);
    auto draw = bind(distribution, ref(generator));

    int x;
    int tries = 0;
    string coin_flip_str;

    for(int i = 0; i < trials; i++){

        coin_flip_str = "";

        while(coin_flip_str.size() < pattern_str.size()){
            x = draw();
            if(x == 1){
                coin_flip_str += "H";
            } else{
                coin_flip_str += "T";
            }
            tries++;
        }

        while(coin_flip_str != pattern_str) {
            coin_flip_str = coin_flip_str.substr(1);
            x = draw();
            if(x == 1){
                coin_flip_str += "H";
            } else{
                coin_flip_str += "T";
            }
            tries++;
        }
    }

    cout << "Expectation: " << double(tries)/double(trials) << endl;

    return 0;
}
