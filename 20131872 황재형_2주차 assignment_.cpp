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
	cout << "�������� ���̰� " << r << "�̸�" <<endl<<
		"���� �ѷ��� " << p << "�̰�" <<endl<<"���� ���̴� " << a << "�̴�."<<endl;
	return 0;
	}
//����2 : a, p�� ����������(int) �����, ��� ���� �Ҽ��� �ڸ��� �������� ������ ���� ����ȴ�.
//ex)  �Ǽ��� �������� �� a ���� 31.1313�̸�, ������ ���ǽ�, a���� 31�̴�.