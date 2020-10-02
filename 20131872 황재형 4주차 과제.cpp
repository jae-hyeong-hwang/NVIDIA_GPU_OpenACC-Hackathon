//20131872 황재형
#include <iostream>
using namespace std;

struct matrix{
	int m; // number of rows
	int n; // number of columns
	float **p; // pointer to 2D array
};
int main(){
	matrix A, B, C;
	cout << "A의 열의 개수 A.n과 B의 행의 개수B.n이 일치하여야 C가 계산되어질 수 있다." << endl;
	cout << "***********************************" << endl;
	cout << "행렬 A의 행의 개수는? ";	cin >> A.m;
	cout << "행렬 A의 열의 개수는? "; cin >> A.n;
	A.p = new float*[A.m];
	for (int i = 0; i < A.m; i++){
		A.p[i] = new float[A.n];
	}
	for (int i = 0; i < A.m; i++){
		for (int j = 0; j < A.n; j++){
			cout << "A행렬의" << i + 1 << "행" << j + 1 << "열의 항은?  ";
			cin >> A.p[i][j];
		}
	}
	cout << "행렬 A는? " << endl;
	for (int i = 0; i < A.m; i++){
		for (int j = 0; j < A.n; j++){
			cout << A.p[i][j] << " ";
		}cout << endl;
	}
	cout << "***********************************" << endl;
	cout << "행렬 B의 행의 개수는? ";	cin >> B.m;
	cout << "행렬 B의 열의 개수는? "; cin >> B.n;
	B.p = new float*[B.m];
	for (int i = 0; i < B.m; i++){
		B.p[i] = new float[B.n];
	}
	for (int i = 0; i < B.m; i++){
		for (int j = 0; j < B.n; j++){
			cout << "B행렬의" << i + 1 << "행" << j + 1 << "열의 항은?  ";
			cin >> B.p[i][j];
		}
	}
	cout << "행렬 B는? " << endl;
	for (int i = 0; i < B.m; i++){
		for (int j = 0; j < B.n; j++){
			cout << B.p[i][j] << " ";
		}cout << endl;
	}
	cout << "***********************************" << endl;
	cout << "C=A*B이며, A의 열의 개수 A.n과 B의 행의 개수B.n이 일치하여야 한다." << endl;
	cout << "C행렬의 행 개수는? " << A.m << endl;
	cout << "C행렬의 열 개수는? " << B.n << endl;
	C.p = new float*[A.m];
	for (int i = 0; i < A.m; i++)
	{
		C.p[i] = new float[B.n];
	}
	for (int i = 0; i < A.m; i++){
		for (int j = 0; j < B.n; j++){
			C.p[i][j] = 0;
			for (int k = 0; k < A.n; k++){
				C.p[i][j] =C.p[i][j]+ A.p[i][k] * B.p[k][j];
			}
		}
	}

	cout << "행렬 C의 값은?" << endl;
	for (int i = 0; i < A.m; i++){
		for (int j = 0; j < B.n; j++){
			cout << C.p[i][j] << " ";
		}cout << endl;
	}
	for (int i = 0; i < A.m; i++)
		delete[] A.p[i];
	delete[] A.p;

	for (int i = 0; i < B.m; i++)
		delete[] B.p[i];
	delete[] B.p;

	for (int i = 0; i < A.m; i++)
		delete[] C.p[i];
	delete[] C.p;

	return 0;
}