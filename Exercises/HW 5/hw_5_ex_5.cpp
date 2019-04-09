#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> process_line(const string &line);

int main(int argc, char* argv[]) {

    if (argc < 2) {
        cout << "No files entered." << endl;
        return 0;
    }

    vector<vector<int>> vec_a;
    vector<vector<int>> vec_b;

    ifstream ifs(argv[1]);
    ofstream ofs("hw_5_ex_5_solution.dat");

    if (!ifs.is_open()) {
        cout << "File could not be opened." << endl;
        return 0;
    }

    string line;
    while (getline(ifs, line)) {

        if (line.empty()) {
            break;
        }

        vec_a.push_back(process_line(line));
    }

    while (getline(ifs, line)) {
        vec_b.push_back(process_line(line));
    }

    vector<vector<int>> vec_sum(vec_a.size(), vector<int> (vec_a[0].size()));

    for (int i = 0; i < vec_a.size(); i++) {
        for (int j = 0; j < vec_a[i].size(); j++) {
            vec_sum[i][j] = vec_a[i][j] + vec_b[i][j];
        }
    }

    for (int i = 0; i < vec_sum.size(); i++) {
        for (int j = 0; j < vec_sum[i].size(); j++) {
            ofs << vec_sum[i][j] << " ";
        }
        ofs << '\n';
    }

    return 0;

}

vector<int> process_line(const string &line){

    istringstream iss(line);
    string elem;
    vector<int> processed_line;

    while(getline(iss,elem, ' ')) {
        processed_line.push_back(stoi(elem));
    }

    return processed_line;

}
