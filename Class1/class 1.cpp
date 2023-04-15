#include <iostream>
using namespace std;

class Class1
{
	int first;
	int second;

public:
	int First, Second;
	void setClass1(int First, int Second)
	{
		First = first;
		Second = second;
	}
	int minutes(static int First, static int Second)
	{
		int minute = First*60 + Second;
		cout << minute;
		return minute;
	}


};

void main()
{
	Class1 Cl1;
	cin >> Cl1.First >> Cl1.Second;
	Cl1.minutes(Cl1.First, Cl1.Second);
}