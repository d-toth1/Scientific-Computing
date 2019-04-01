#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> line_sum(const string &line);

int main(int argc, char* argv[]) {

    if (argc < 2) {
        cout << "No files entered to read from." << endl;
        return 0;
    }

    ifstream ifs(argv[1]);
    ofstream ofs("hw_5_ex_2_output.dat");
    string line;

    vector<vector<int>> sums;

    if (!ifs.is_open()) {
        cout << "File could not be opened." << endl;
        return 0;
    }

    while(getline(ifs, line)) {
        sums.push_back(line_sum(line));
    }

    for (int i = 0; i < sums.size(); i++) {
        int line_total = 0;
        for (int j = 0; j < sums[i].size(); j++) {
            line_total += sums[i][j];
        }
        ofs << line_total << '\n';
    }
    return 0;
}

vector<int> line_sum(const string &line) {

    istringstream iss(line);
    string elem;
    vector<int> processed_line;

    while(getline(iss, elem, ';')) {
        processed_line.push_back(stod(elem));
    }

    return processed_line;
}
