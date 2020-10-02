//20131872 Ȳ����
#include <iostream>
using namespace std;

struct matrix{
	int m; // number of rows
	int n; // number of columns
	float **p; // pointer to 2D array
};
int main(){
	matrix A, B, C;
	cout << "A�� ���� ���� A.n�� B�� ���� ����B.n�� ��ġ�Ͽ��� C�� ���Ǿ��� �� �ִ�." << endl;
	cout << "***********************************" << endl;
	cout << "��� A�� ���� ������? ";	cin >> A.m;
	cout << "��� A�� ���� ������? "; cin >> A.n;
	A.p = new float*[A.m];
	for (int i = 0; i < A.m; i++){
		A.p[i] = new float[A.n];
	}
	for (int i = 0; i < A.m; i++){
		for (int j = 0; j < A.n; j++){
			cout << "A�����" << i + 1 << "��" << j + 1 << "���� ����?  ";
			cin >> A.p[i][j];
		}
	}
	cout << "��� A��? " << endl;
	for (int i = 0; i < A.m; i++){
		for (int j = 0; j < A.n; j++){
			cout << A.p[i][j] << " ";
		}cout << endl;
	}
	cout << "***********************************" << endl;
	cout << "��� B�� ���� ������? ";	cin >> B.m;
	cout << "��� B�� ���� ������? "; cin >> B.n;
	B.p = new float*[B.m];
	for (int i = 0; i < B.m; i++){
		B.p[i] = new float[B.n];
	}
	for (int i = 0; i < B.m; i++){
		for (int j = 0; j < B.n; j++){
			cout << "B�����" << i + 1 << "��" << j + 1 << "���� ����?  ";
			cin >> B.p[i][j];
		}
	}
	cout << "��� B��? " << endl;
	for (int i = 0; i < B.m; i++){
		for (int j = 0; j < B.n; j++){
			cout << B.p[i][j] << " ";
		}cout << endl;
	}
	cout << "***********************************" << endl;
	cout << "C=A*B�̸�, A�� ���� ���� A.n�� B�� ���� ����B.n�� ��ġ�Ͽ��� �Ѵ�." << endl;
	cout << "C����� �� ������? " << A.m << endl;
	cout << "C����� �� ������? " << B.n << endl;
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

	cout << "��� C�� ����?" << endl;
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