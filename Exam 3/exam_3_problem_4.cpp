#include <complex>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

std::complex<double> f_c(std::complex<double> z, std::complex<double> c);

int main(int argc, char* argv[]){

    int N = std::stoi(argv[1]);
    int K = std::stoi(argv[2]);

    std::ofstream ofs("output.csv");

    double x, y;
    std::complex<double> c;
    std::complex<double> z;


    for(int j = 0; j <= N; j++){
        for(int k = 0; k <= N; k++){
            int it = 0;
            z = 0;
            x = -2.0 + ((4.0*j)/double(N));

            y = -2.0 + ((4.0*k)/double(N));


            c.real(x);
            c.imag(y);
            while(it < K && std::abs(z) <= 2){
                z = f_c(z, c);
                it++;
            }
            if(it == K && std::abs(z) <= 2){
                ofs << std::setprecision(15) << std::fixed << c.real() << "," <<
                std::setprecision(15) << std::fixed << c.imag() << std::endl;
            }
        }
    }

    return 0;
}

std::complex<double> f_c(std::complex<double> z, std::complex<double> c){
    return std::pow(z, 2.0) + c;
}
