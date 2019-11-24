#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

class MonteCarlo{
    private:
    double t;
    double q;
    double a;
    double b;

    public:
    MonteCarlo(double t, double q, double a, double b){
    this -> t = t;
    this -> q = q;
    this -> b = b;
    this -> a = a;
    }

    double f(double x)
    {
        return t*(1+t*cos(q+x))/pow(t+1+2*t*cos(q+x),1.5);
    }

    double fRand(double fMin, double fMax){

    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);

    }

    double calculating(int n)
    {
        double xSum = 0;
        double ySum = 0;
        double sum = 0;
        srand(time(NULL));
        for (int i = 0; i < n; i++)
        {
            xSum = fRand(a,b);
            sum += f(xSum);
        }
        return abs( b - a ) * sum / n;
    }
};



int main() {

    for ( double t = 0; t < 1; t+=0.005 ){
         MonteCarlo field(t, 5, 0, 2*3.14);
        cout << t << " integral = "  << field.calculating(1000000) << endl;
    }
    return 0;
}
