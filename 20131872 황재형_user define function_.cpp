#include<iostream>
#include<cmath>
using namespace std;
void ���ѷ����̱��ϱ�()
{
	cout.precision(6);
	const double pi = atan(1.0)*4.0;
	double r, a, p;
	cin >> r;
	p = 2 * pi*r;
	a = pi*r*r;
	cout << "�������� ���̰� " << r << "�̸�" << endl <<
		"���� �ѷ��� " << p << "�̰�" << endl << "���� ���̴� " << a << "�̴�." << endl;
	;
}
int main()
{
	cout << "����� ���� �Լ� '���ѷ����̱��ϱ�'"<<endl;
	���ѷ����̱��ϱ�();
	return 0;
}