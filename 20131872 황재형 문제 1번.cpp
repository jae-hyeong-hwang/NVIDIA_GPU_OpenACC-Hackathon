//20131872 황재형
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
	cout << "structure array student의 크기는" << sizeof(a) << "byte이다" << endl;
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
	cout <<"학생들의 몸무게의 총 합은"<< sum<<"kg이다." << endl;
	float avg = sum / 10;
	cout << "학생들의 몸무게(kg)의 평균은 " << avg <<"kg이다."<< endl;
	return 0;
}