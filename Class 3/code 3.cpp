#include <iostream>
using namespace std;

class times
{
public:
    bool value;
    int minut;
    int secund;
public:
    times() {
        minut = 0;
        secund = 0;
    };
    times(int newMinuts, int newSecond) {
        minut = newMinuts;
        secund = newSecond;
    };
    bool operator == (const times& times) {
        return this->minut == times.minut && this->secund == times.secund;
    };
    bool operator != (const times& times) {
        return this->minut == times.minut && this->secund == times.secund;
    };
};

int masage(int X, int Y)
{
    cout << X << ":" << Y;
    return X, Y;
}

int count(int A, int B, int C)
{
    B = B + (A * 60);
    B = B - C;
    A = B / 60;
    B = B % 60;
    return masage(A, B);
}

int main()
{
    int show;
    times vrema(60, 60);
    times vremaTwo(30, 60);
    bool bulFlag = vrema == vremaTwo;
    cout << bulFlag << endl;
    cin >> vrema.minut >> vrema.secund;
    masage(vrema.minut, vrema.secund);
    cout << endl;
    int vichet;
    cin >> vichet;
    count(vrema.minut, vrema.secund, vichet);


}
