//20131872 황재형 Homework 예제2
#include<iostream>
using namespace std;
void main()
{
	float mph, kph, mps;
	cin >> mph;
	kph = 1.6*mph;
	mps = 0.45*mph;
	cout << mph << "spd[mph]는" << kph << "spd[kph]이고, " << endl
		<< mph << "spd[mph]는" << mps << "spd[mps]이다" << endl;
}