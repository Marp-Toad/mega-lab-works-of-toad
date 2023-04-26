#include <iostream>
using namespace std;
int c, d;

class Pair
{
protected:

    int first, second;

public:

    Pair()
    {
        first = 0;
        second = 0;
    }

    Pair(int A, int B)
    {
        first = A;
        second = B;
    }

    Pair(const Pair& Frog)
    {
        first = Frog.first;
        second = Frog.second;
    }

    int sloj(int first, int second, int c, int d)
    {
        second = second + d;
        first = first + c + second/100;
        second = second % 100;
    }

    int getPair()
    {
        return first, second;
    }

    void showAtt()
    {
        cout << first << "." << second;
    }

    ~Pair()
    {

    }
};

class Money :public Pair
{
public:

    int rub, kop;

public:
    Money()
    {
        first = 0;
        second = 0;
    }

    Money(int A, int B, int R, int K) :Pair(A, B)
    {
        rub = R;
        kop = K;
    }

    Money(const Money& Frog)
    {
        rub = Frog.rub;
        kop = Frog.kop;
    }

    int sloj(int rub, int kop, int c, int d)
    {
        kop = kop + d;
        rub = rub + c + kop / 100;
        kop = kop % 100;
        return showAtt(rub, kop);
    }

    int vich(int rub, int kop, int c, int d)
    {
        kop = (rub - c) * 100 + kop - d;
        rub = kop / 100;
        kop = kop % 100;
        return showAtt(rub, kop);
    }

    int dele(int rub, int kop, int c)
    {
        kop = ((rub - c) * 100 + kop) / c;
        rub = kop / 100;
        c = ((rub - c) * 100 + kop) % c;
        kop = kop % 100;
        return showAtt(rub, kop);
    }

    int getMoney()
    {
        return rub, kop;
    }

    int showAtt(int rub, int kop)
    {
        cout << "У вас деняк : " << rub << "." << kop << endl;
        return rub, kop;
    }

    ~Money()
    {

    }
};

int main() {
    setlocale(LC_ALL, "RUS");
    Money Frog1;
    cin >> Frog1.rub >> Frog1.kop;
    Frog1.showAtt(Frog1.rub, Frog1.kop);
    int kapets;
    cout << "выберите функцию: 1 - прибавка, 2 - убавка, 3 - деление" << endl;
    cin >> kapets;
    switch (kapets)
    {
    case 1:
        cin >> c >> d;
        Frog1.sloj(Frog1.rub, Frog1.kop, c, d);
        break;
    case 2:
        cin >> c >> d;
        Frog1.vich(Frog1.rub, Frog1.kop, c, d);
        break;
    case 3:
        cin >> c;
        Frog1.dele(Frog1.rub, Frog1.kop, c);
    default:
        break;
    };
}
