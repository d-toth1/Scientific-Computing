#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

double mean(vector<double> v);
double std_dev(vector<double> v);

int main(int argc, char* argv[]){

    if(argc < 2){
        cout << "Please enter a tolerance." << endl;
        return 0;
    }

    ifstream ifs("data.txt");
    ofstream lower("lower_anomalies.txt");
    ofstream upper("upper_anomalies.txt");

    double tolerance = stod(argv[1]);
    vector<double> data;

    string line;
    while(getline(ifs, line)){
        data.push_back(stod(line));
    }

    sort(data.begin(), data.end());

    double average_value = mean(data);
    double sigma = std_dev(data);

    double lower_limit = average_value - tolerance*sigma;
    double upper_limit = average_value + tolerance*sigma;

    for(int i = 0; i < data.size(); i++){
        if(data[i] < lower_limit) {
            lower << data[i] << '\n';
        } else if(data[i] > upper_limit){
            upper << data[i] << '\n';
        }
    }
    return 0;
}

double mean(vector<double> v){

    double total = 0.0;
    for(int i = 0; i < v.size(); i++){
        total += v[i];
    }

    return total/double(v.size());
}

double std_dev(vector<double> v){

    double x_bar = mean(v);
    double var = 0.0;

    for(int i = 0; i < v.size(); i++){
        var += pow(x_bar - v[i], 2.0);
    }

    var /= (v.size() - 1.0);

    return pow(var, 0.5);
}
