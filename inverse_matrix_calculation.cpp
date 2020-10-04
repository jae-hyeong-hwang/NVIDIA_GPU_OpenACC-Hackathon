#include <iostream>
using namespace std;
//20131872 황재형

void read_A(double A[2][2]);
void inv_2x2(double A[2][2], double Ai[2][2]);
void check_inv(double A[2][2], double Ai[2][2]);

int main(){
	double A[2][2];
	double Ai[2][2];
	read_A(A);
	inv_2x2(A, Ai);
	check_inv(A, Ai);
	return 0;
}

void read_A(double A[2][2]){
	int i, j;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			cout << "A행렬의" << i + 1 << "행 " << j + 1 << "열은?" << endl;
			cin >> A[i][j];
		}
	}
}

void inv_2x2(double A[2][2], double Ai[2][2])
{
	double d;
	d = A[0][0] * A[1][1] - A[0][1] * A[1][0];
	Ai[0][0] = A[1][1] / d;
	Ai[0][1] = -A[0][1] / d;
	Ai[1][0] = -A[1][0] / d;
	Ai[1][1] = A[0][0] / d;
}

void check_inv(double A[2][2], double Ai[2][2])
{
	double check[2][2];
	int i, j;

	for (i = 0; i < 2; i++){
		for (j = 0; j < 2; j++){
			check[i][j] = A[i][0] * Ai[0][j] + A[i][1] * Ai[1][j];
		}
	}

	cout << "A=" << endl;
	for (i = 0; i < 2; i++){
		for (j = 0; j < 2; j++){
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "Ai=" << endl;
	for (i = 0; i < 2; i++){
		for (j = 0; j < 2; j++){
			cout << Ai[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "A*Ai=" << endl;
	for (i = 0; i < 2; i++){
		for (j = 0; j < 2; j++){
			cout << check[i][j] << " ";
		}
		cout << endl;
	}
	cout << "행렬A와 역행렬 inverse A의 곱은 E이다." << endl;
}
