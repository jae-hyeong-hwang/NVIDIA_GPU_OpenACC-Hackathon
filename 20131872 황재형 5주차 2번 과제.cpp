/*�ڿ��� n�� �Ҽ����� �ƴ����� �����Ϸ���,
2��p�� ��n�� ������ �ִ� ��� �Ҽ� p�� n�� ������ ����,
������ �������� ������ �Ҽ��̰�, ������ �������� �ռ����̴�
��ó :[���̹� ���Ĺ��] �Ҽ�[prime number, ���](�λ���)*/
#include<iostream>
using namespace std;
int main()
{
	int i;
	cout << "prime numbers between 10 and 100 are"<<endl;
	for (int i = 10; i <= 100; i++)
	{
		if ((i % 2 != 0) && (i % 3 != 0) && (i % 5 != 0) && (i % 7 != 0))
		{
			cout << i << " "; 
		}
	}cout << endl;
	return 0;
}