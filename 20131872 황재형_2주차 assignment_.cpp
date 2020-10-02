#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	cout.precision(6);
	const double pi = atan(1.0)*4.0;
	double r, a, p;
	cin >> r;
	p = 2 * pi*r;
	a = pi*r*r;
	cout << "반지름의 길이가 " << r << "이면" <<endl<<
		"원의 둘레는 " << p << "이고" <<endl<<"원의 넓이는 " << a << "이다."<<endl;
	return 0;
	}
//문제2 : a, p를 정수형으로(int) 선언시, 결과 값은 소수점 자리는 지워지고 정수의 값만 도출된다.
//ex)  실수로 정의했을 때 a 값이 31.1313이면, 정수로 정의시, a값은 31이다.