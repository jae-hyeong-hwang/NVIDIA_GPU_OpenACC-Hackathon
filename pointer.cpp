#include<iostream>
#include<cmath>
#include "point.h"
using namespace std;
void point::set_zero() {
	x = 0.; y = 0.;
}

void point::set_value(double a, double b) {
	//put a and b
	x = a; y = b;
}

void point::translate(double a, double b) {// 입력받은 a값, b값으로부터 x 좌표를 a만큼, y좌표를 b만큼 이동
	cout << "translate " << a << " from x coordinate and";	x = a + x;
	cout << " translate " << b << " from y coordinate is" << endl;	y = y + b;
}
void point::rotate(double angle /* degree */) {
	// x좌표와 y좌표가 이루는 각을 theta라고 정의하고, angle만큼 이동할 경우,
	// 원주좌표계에서 사잇각이 theta+angle인 부채꼴로 생각하여, 이동시킨 좌표의 값을 구한다.
	// 반지름이 root(x^2+y^2)인 원으로 생각한다.
	double pi = atan(1.0) * 4.0;
	angle = angle*pi / 180.0;
	double theta = atan(y / x);
	double x_zero; double y_zero;
	x_zero = x; y_zero = y;
	cout << "rotate " << angle * 180 / pi << " degree from (" << x << "," << y << ") is ";
	x = sqrt(x_zero*x_zero + y_zero*y_zero)*cos(theta + angle);
	y = sqrt(x_zero*x_zero + y_zero*y_zero)*sin(theta + angle);
}

void point::rotate(double angle /* degree */, double x0, double y0) {

	double pi = atan(1.0) * 4.0;
	angle = angle*pi / 180.0;
	double theta = atan(y0 / x0);
	double x_zero; double y_zero;
	x_zero = x0; y_zero = y0;
	cout << "rotate " << angle * 180 / pi << " degree from (" << x0 << "," << y0 << ") is ";
	x = sqrt(x_zero*x_zero + y_zero*y_zero)*cos(theta + angle);
	y = sqrt(x_zero*x_zero + y_zero*y_zero)*sin(theta + angle);
}


void point::scale(double r) {
	cout << "result of (" << x << ", " << y << ") to scale " << r << " is ";
	x = x*r; y = y*r;
}
void point::show() {
	cout << "(x,y) = " << "(" << x << "," << y << ")" << endl;
}
