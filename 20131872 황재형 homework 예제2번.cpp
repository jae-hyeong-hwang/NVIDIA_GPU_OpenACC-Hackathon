//20131872 Ȳ���� Homework ����2
#include<iostream>
using namespace std;
void main()
{
	float mph, kph, mps;
	cin >> mph;
	kph = 1.6*mph;
	mps = 0.45*mph;
	cout << mph << "spd[mph]��" << kph << "spd[kph]�̰�, " << endl
		<< mph << "spd[mph]��" << mps << "spd[mps]�̴�" << endl;
}