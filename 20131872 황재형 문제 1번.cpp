//20131872 Ȳ����
#include<iostream>
using namespace std;
struct student
{
	char name[10][20];
	float weight[10];
};

int main()
{
	student a;
	cout << "structure array student�� ũ���" << sizeof(a) << "byte�̴�" << endl;
	int i;
	for (i = 0; i < 10; i++)
	{
		cout << "student's name is  ";
		cin >> a.name[i];
		cout << "student's weight is ";
		cin >> a.weight[i];
	}
	float sum = 0;
	for (i = 0; i < 10; i++)
	{
		sum = sum + a.weight[i];
	};
	cout <<"�л����� �������� �� ����"<< sum<<"kg�̴�." << endl;
	float avg = sum / 10;
	cout << "�л����� ������(kg)�� ����� " << avg <<"kg�̴�."<< endl;
	return 0;
}