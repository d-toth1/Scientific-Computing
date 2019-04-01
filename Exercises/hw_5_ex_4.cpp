#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>

using namespace std;

int main(int argc, char* argv[]) {

    if (argc < 2) {
        cout << "No files entered." << endl;
        return 0;
    }

    vector<int> alphacount(26);
    int total = 0;
    vector<string> files;

    for (int i = 1; i < argc; i++) {
        files.push_back(argv[i]);
    }

    ifstream ifs;

    for (auto i : files) {
        ifs.clear();
        ifs.open(i);
        if (!ifs.is_open()) {
            cout << "Error: could not open file." << endl;
        }
        char c;
        while (ifs.get(c) && c!=EOF) {

            if (isalpha(c)) {
                alphacount[tolower(c) - 'a'] ++;
                total ++;
            }
        }
    }
    for (int i = 0; i < alphacount.size(); i++) {
        cout << (char) ('a' + i) << " count: " << alphacount[i] << endl;
        cout << (char) ('a' + i) << " frequency: " << ((alphacount[i] + 0.0 )/ (total + 0.0)) << endl;
        cout << '\n'; 
    }
    return 0;
}
