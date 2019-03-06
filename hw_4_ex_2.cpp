#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void print_high_score (const vector<int> &scores_mod, const vector<string> &names_mod);
void print_low_score (const vector<int> &scores_mod, const vector<string> &names_mod);

int main () {

    vector<string> names;
    vector<int> scores;
    int user_score;
    bool valid_entry = true;
    string user_name;

    while (true) {
        cout << "Enter a first name: ";
        cin >> user_name;
        if (user_name == "EndInput") {
            break;
        }
        names.push_back(user_name);
        sort(names.begin(), names.end());
        for (int i = 0; i < names.size(); i++) {
            if (names[i-1] == names[i]) {
                names.erase(names.begin() + i);
                valid_entry = false;
                break;
            }
        }
        if (valid_entry) {
            cout << "Enter their score: ";
            cin >> user_score;
            if (user_score < 0 || user_score > 100) {
                names.pop_back();
                break;
            }
            scores.push_back(user_score);
        } else {
            break;
        }
    }

    print_high_score(scores, names);
    cout << endl;
    print_low_score(scores, names);

    return 0;
}

void print_high_score (const vector<int> &scores_mod, const vector<string> &names_mod) {

    int high_score = scores_mod[0];
    vector<string> high_scorers;

    for (int i = 0; i < scores_mod.size(); i++) {
        if (scores_mod[i] > high_score) {
            high_score = scores_mod[i];
        }
   }
   for (int i = 0; i < scores_mod.size(); i++) {
       if (scores_mod[i] == high_score) {
           high_scorers.push_back(names_mod[i]);
       }
   }
    cout << "The high score was " << high_score << " and was scored by: ";
    for (int i = 0; i < high_scorers.size(); i++) {
        cout << high_scorers[i] << " ";
    }
}
void print_low_score (const vector<int> &scores_mod, const vector<string> &names_mod) {

    int low_score = scores_mod[0];
    vector<string> low_scorers;

    for (int i = 0; i < scores_mod.size(); i++) {
        if (scores_mod[i] < low_score) {
            low_score = scores_mod[i];
        }
    }
    for (int i = 0; i < scores_mod.size(); i++) {
        if (scores_mod[i] == low_score) {
            low_scorers.push_back(names_mod[i]);
        }
    }
    cout << "The low score was " << low_score << " and was scored by: ";
    for (int i = 0; i < low_scorers.size(); i++) {
        cout << low_scorers[i] << " ";
    }
}
