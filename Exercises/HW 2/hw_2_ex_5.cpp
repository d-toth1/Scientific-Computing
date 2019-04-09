//Makes use or adaptation of code presented on Sakai or in tutorial
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int k=0;
    double term, nextterm, sum=0.0, tol = 0.0, epsilon=1e-6;
    
    while (tol <=0){
        cout << "Enter an error tolerance, preferably a small number between 0 and 1" << endl;
        cin >> tol;
    }
    
    term = 1/(k+2+log(pow(k,2.5)+1));
    while(abs(term) > tol){
        k++;
        sum += term;
        nextterm = pow(-1,k*1.0)/(1+2+log(pow(k,2.5) + 1));
        if (abs(term-nextterm) < epsilon) break;
        term = nextterm;
        cout << sum << endl;
    }

    cout << "The sum of the series is " << sum << " calculated using " << k << " terms." << endl;
    
    return 0;
}
