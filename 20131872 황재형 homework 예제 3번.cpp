#include<iostream>
using namespace std;
void main()
{
	float knots, kph, mps;
	cin >> knots;
	kph = 1.85*knots;
	mps = 0.5*knots;
	cout << knots << "spd[knots]는" << 1.85*knots << "spd[kph]이고, " << endl
		<< knots << "spd[knots]는" << 0.5*knots << "spd[mps]이다." << endl;
}