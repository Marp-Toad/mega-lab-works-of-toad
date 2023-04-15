#include <iostream>
using namespace std;

class Toad
{

    double a, b, c;

public:

    Toad()
    {
        a = 0;
        b = 0;
        c = 0;
    }

    Toad(double A, double B, double C)
    {
        a = A;
        b = B;
        c = C;
    }

    Toad(const Toad &Frog)
    {
        a = Frog.a;
        b = Frog.b;
        c = Frog.c;
    }
    double getToad()
    {
        return a, b, c;
    }
  
    void showAtt()
    {

        cout << a << "\n";
        cout << b << "\n";
        cout << c << "\n";

    }

    ~Toad()
    {

    }
};

int main() {

    Toad Frog1;
    Toad Frog2(1.0, 2.1, 3.21);
    Toad Frog3 = Frog1;

    Frog2.showAtt();
}
