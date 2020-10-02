#include <iostream>
#include "point.h"
using namespace std;

// 2. main()
int main()
{
	point p1;  	p1.show(); 
	p1.set_zero(); 	p1.show();

	double a,b;	cin >> a;	cin >> b;
	p1.set_value(a, b); 	p1.show();
	p1.translate(a, b); 	p1.show();
	p1.rotate(a*10); 		p1.show();
	p1.rotate(a*10, a, b); 	p1.show();
	p1.scale(b*10); 		p1.show();

	return 0;
}
