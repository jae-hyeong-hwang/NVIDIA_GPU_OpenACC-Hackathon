#include<iostream>
#include<cmath>
using namespace std;
void 원둘레넓이구하기()
{
	cout.precision(6);
	const double pi = atan(1.0)*4.0;
	double r, a, p;
	cin >> r;
	p = 2 * pi*r;
	a = pi*r*r;
	cout << "반지름의 길이가 " << r << "이면" << endl <<
		"원의 둘레는 " << p << "이고" << endl << "원의 넓이는 " << a << "이다." << endl;
	;
}
int main()
{
	cout << "사용자 정의 함수 '원둘레넓이구하기'"<<endl;
	원둘레넓이구하기();
	return 0;
}