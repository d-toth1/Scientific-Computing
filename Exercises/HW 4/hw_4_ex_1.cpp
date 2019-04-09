#include <iostream>
#include <vector>
using namespace std;

double vec_max (const vector<double> &a);
double vec_min (const vector<double> &b);

int main () {

    vector<double> user_entries;
    double user_max, user_min;

    cout << "Enter a real number, or a string to exit: ";
    {
        double entry;
        while (cin >> entry) {
            user_entries.push_back(entry);
            cout << "Enter a real number, or a string to exit: ";
        }

    }

    user_max = vec_max(user_entries);
    user_min = vec_min(user_entries);

    cout << "The maximum value is: " << user_max << endl;
    cout << "The minimum value is: " << user_min << endl;

    return 0;
}


double vec_max (const vector<double> &a) {
    double max_value = a[0];
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > max_value) {
            max_value = a[i];
        }
    }
    return max_value;
}

double vec_min (const vector<double> &b) {
    double min_value = b[0];
    for (int i = 0; i < b.size(); i++) {
        if (b[i] < min_value) {
            min_value = b[i];
        }
    }
    return min_value;
}
