#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector<double> processed_line(const string &line);
void x_bar(const vector<double> &x);
void y_bar(const vector<double> &y);
void s_x(const vector<double> &x);
void s_y(const vector<double> &y);
void corr_coeff(const vector<double> &x, const vector<double> &y);
void y_hat(const vector<double> &x, const vector<double> &y);

int main(int argc, char* argv[]) {

    if (argc < 2) {
        cout << "No files entered." << endl;
        return 0;
    }

    ifstream ifs(argv[1]);

    vector<double> x_obs;
    vector<double> y_obs;


    if (!ifs.is_open()) {
        cout << "The file could not be opened." << endl;
        return 0;
    }

    istream_iterator<double> start(ifs), end;
    vector<double> total_obs(start,end);

    for (int i = 0; i < total_obs.size(); i++) {
        if (i % 2 == 0) {
            x_obs.push_back(total_obs[i]);
        } else {
            y_obs.push_back(total_obs[i]);
        }
    }

    if (x_obs.size() == y_obs.size() && x_obs.size() > 1) {
        x_bar(x_obs);
        y_bar(y_obs);
        s_x(x_obs);
        s_y(y_obs);
        corr_coeff(x_obs, y_obs);
        y_hat(x_obs, y_obs);
    } else {
        cout << "Sample size is too small." << endl;
    }

    return 0;
}

void x_bar(const vector<double> &x) {
    double sum = 0.0;
    for (int i = 0; i < x.size(); i++) {
        sum += x[i];
    }
    cout << "Sample mean of x: " << (sum/double(x.size())) << endl;
    return;
}

void y_bar(const vector<double> &y) {
    double sum = 0.0;
    for (int i = 0; i < y.size(); i++) {
        sum += y[i];
    }
    cout << "Sample mean of y: " << (sum/double(y.size())) << endl;
    return;
}

void s_x(const vector<double> &x) {
    double entries_sum = 0.0;
    double new_sum = 0.0;
    double x_;
    for (int i = 0; i < x.size(); i++) {
        entries_sum += x[i];
    }
    x_ = entries_sum/double(x.size());
    for (int i = 0; i < x.size(); i++) {
        new_sum += pow((x[i] - x_), 2.0);
    }
    cout << "Std. Dev. of x: " <<  sqrt((new_sum/(x.size() - 1.0))) << endl;
    return;
}

void s_y(const vector<double> &y) {
    double entries_sum = 0.0;
    double new_sum = 0.0;
    double y_;
    for (int i = 0; i < y.size(); i++) {
        entries_sum += y[i];
    }
    y_ = entries_sum/double(y.size());
    for (int i = 0; i < y.size(); i++) {
        new_sum += pow((y[i] - y_), 2.0);
    }
    cout << "Std. Dev. of y: " << sqrt((new_sum/(y.size() - 1.0))) << endl;
    return;
}

void corr_coeff(const vector<double> &x, const vector<double> &y) {
    double x_sum = 0.0;
    double y_sum = 0.0;
    double new_x_sum = 0.0;
    double new_y_sum = 0.0;
    double r_sum = 0.0;
    double x_, y_, std_x, std_y;
    for (int i = 0; i < x.size(); i++) {
        x_sum += x[i];
    }
    for (int i = 0; i < y.size(); i++) {
        y_sum += y[i];
    }
    x_ = x_sum/double(x.size());
    y_ = y_sum/double(y.size());
    for (int i = 0; i < x.size(); i++) {
        new_x_sum += pow((x[i] - x_), 2.0);
    }
    for (int i = 0; i < y.size(); i++) {
        new_y_sum += pow((y[i] - y_), 2.0);
    }
    std_x = sqrt((new_x_sum/(x.size() - 1.0)));
    std_y = sqrt((new_y_sum/(y.size() - 1.0)));
    if (std_x == 0 || std_y == 0) {
        cout << "The sample correlation is undefined." << endl;
    } else {
        for (int i = 0; i < x.size(); i++) {
            r_sum += (((x[i] - x_)/(std_x))*((y[i] - y_)/(std_y)));
        }
        cout << "The sample correlation is: " <<  r_sum/double(x.size()) << endl;
    }
    return;
}

void y_hat(const vector<double> &x, const vector<double> &y) {
    double m, b;
    double x_sum = 0.0;
    double y_sum = 0.0;
    double new_x_sum = 0.0;
    double new_y_sum = 0.0;
    double r_sum = 0.0;
    double x_, y_, std_x, std_y;

    for (int i = 0; i < x.size(); i++) {
        x_sum += x[i];
    }
    for (int i = 0; i < y.size(); i++) {
        y_sum += y[i];
    }
    x_ = x_sum/double(x.size());
    y_ = y_sum/double(y.size());
    for (int i = 0; i < x.size(); i++) {
        new_x_sum += pow((x[i] - x_), 2.0);
    }
    for (int i = 0; i < y.size(); i++) {
        new_y_sum += pow((y[i] - y_), 2.0);
    }
    std_x = sqrt((new_x_sum/(x.size() - 1.0)));
    std_y = sqrt((new_y_sum/(y.size() - 1.0)));
    if (std_x == 0) {
        cout << "The least squares regression line is undefined." << endl;
    } else if (std_x != 0 && std_y == 0) {
        cout << "The least squares regression line is: y_hat = " << y_ << endl;
    } else {
        for (int i = 0; i < x.size(); i++) {
            r_sum += (((x[i] - x_)/(std_x))*((y[i] - y_)/(std_y)));
        }
        m = (r_sum/double(x.size()))*(std_y/std_x);
        b = y_ - m*x_;
        cout << "Least squares regression line: y_hat = " << m << "x + " << b << endl;
    }
    return;
}
