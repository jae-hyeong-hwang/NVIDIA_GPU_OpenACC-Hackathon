/*•Write a SORTING Program
–Sort the following list of numbers in the descending order.
int a[10] = { 7, 2, 5, 9, 4, 1, 2, 10, 5, 6 };*/
#include<iostream>
using namespace std;
int main(){
	int a[10] = { 7, 2, 5, 9, 4, 1, 2, 10, 5, 6 };
	for (int i = 0; i<10; i++)
	{
		for (int j = 0; j<10; j++)
		{
			if (a[i]>a[j])
			{
				int max = a[i];
				a[i] = a[j];
				a[j] = max;
			}
		}
	}
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	return 0;
	}
