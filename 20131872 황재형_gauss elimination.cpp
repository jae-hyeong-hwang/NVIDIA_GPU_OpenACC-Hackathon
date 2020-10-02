#include <iostream>
#include<fstream>
using namespace std;
void read(double **&A, double *&b, unsigned int &n);
void upper_tri(double **&A, double *&b, double *&x, double **&U, double *&y, unsigned int &n);
void back_sub(double **&U, double *&y, double *&x, unsigned int &n);
void check_soln(double **&A, double *&b, double *&x, unsigned int &n);
void delete_mem(double **&A, double *&b, double *&x, double **&U, double *&y, unsigned int &n);

int main() {
	cout << "input n=10" << endl << "n=? ";
	unsigned int n; cin >> n;
	double **A, *b, *x; 	double **U, *y;

	A = new double *[n]; //allocate dynamic memory
	for (unsigned int i = 0; i < n; i++)//n��n��
		A[i] = new double[n];
	b = new double[n];
	x = new double[n];

	U = new double *[n]; //allocate dynamic memory
	for (unsigned int i = 0; i < n; i++)//n��n��
		U[i] = new double[n];
	y = new double[n];

	read(A, b, n); // read from txt.file
	upper_tri(A, b, x, U, y, n); // upper triangular
	back_sub(U, y, x, n); // get values through back substitution
	check_soln(A, b, x, n); // check values through check_solution
	delete_mem(A, b, x, U, y, n); // delete all dynamic memories
	return 0;
}

void read(double **&A, double *&b, unsigned int &n)
{
	unsigned int i, j;
	fstream f;
	cout.precision(15); // �Ҽ��� 15° �ڸ����� �б�
						//*************** txt file �κ��� ���� �о���̱�*****************
	f.open("���콺(1).txt"); // n*n���� ���ڰ� �ԷµǾ��ִ� txt������ �̸�
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			f >> A[i][j]; // �о���̱�
		}
	}f.close();
	cout << endl;
	f.open("���콺(2).txt"); // n���� ���ڰ� �ԷµǾ� �ִ� txt ������ �̸�
	for (i = 0; i < n; i++)
	{
		f >> b[i]; //�о���̱�
	}
	f.close();
	cout << "************* read A & b from txt.file **************" << endl << endl;
	cout << "A[i][j]�� b[i]" << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout << A[i][j] << " ";  // n�� n�� A ���
		}
		cout << " �� " << b[i] << endl; // n�� 1�� b ���
	}cout << endl;
	// ���� ��� 2x+3y=1, 4x+6y=2�� ���, 1��1���� 2, 1��2���� 3, 2�� 1���� 4, 2�� 2���� 6�� ǥ���� ��� 1����
	// 1��1���� 1, 2�� 1���� 2 �� ��Ÿ���� ��� 1���� �ξ� ���� �������� ����� �ظ� ��ķ� ǥ��.
	//  "��" �����ʿ� ���� ���� ǥ��.

}

void upper_tri(double **&A, double *&b, double *&x, double **&U, double *&y, unsigned int &n) {
	unsigned int i, j, k;
	double d;
	cout << "******************pivoting*****************" << endl;
	for (i = 0; i < n; i++) {
		for (j = 1; j < n; j++) {
			if (A[i][i]<A[j][i]) {
				for (k = 0; k < n; k++) {
					d = A[i][k];
					A[i][k] = A[j][k];
					A[j][k] = d;
				}
				double e = b[i];
				b[i] = b[j];
				b[j] = e;
			}
		}
	} // ������� A�� 1��1����(�ڵ忡���� 0��0���� ǥ����) A�� 2�� 1���� ���Ͽ��� ��,
	  //A�� 2�� 1���� �� ũ�ٸ� A�� 1�� 1���� 2��1��, 1�� 2���� 2��2��...�� n�� ���� ��� �ٲپ��ش�.
	  // ���� b�� 1��� 2���� �ٲپ����� �ݺ������ν�, �� �������� ���� ū ���ڰ� ���� �� �ֵ��� �Ѵ�.

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout << A[i][j] << " ";
		}cout << "��" << b[i] << endl;
	}
	

	for (k = 0; k < n - 1; k++)
		for (i = k; i < n - 1; i++)
		{
			double c = (A[i + 1][k] / A[k][k]); //upper triangular ����.
			b[i + 1] -= c*b[k];   // ���� ��, 2��1���� 1��1��(���⼭�� 0��0���� ǥ���Ǿ�����)�� ���� ���� c��� �ϸ�
			for (j = 0; j < n; j++)// �켱 b����� 2��1������ 1��1���� c�� ���� ���� ����.
				A[i + 1][j] -= c*A[k][j];// ���� A����� 2�� 1���� 1�� 1���� c�� ���� ���� ����,
		}                                   // ���������� 2�� 2���� 1�� 2���� c�� ���� ���� �� ���� �����ϸ� n������ �ݺ��Ѵ�.(�ڵ忡���� n-1���̴�)

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			U[i][j] = A[i][j];  // upper tri �� ����� U���(n by n array)�� �Ҵ��Ѵ�
			y[i] = b[i];       // ���������� b����� ����� y ��Ŀ� �����Ѵ�.
		}
	}

	cout << "****************** upper triangular ******************" << endl;
	cout << endl << "U[i][j]   �� y[i]" << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) { // upper tri �� ����� ���(U[i][j] , y[i][j])
			cout << U[i][j] << "  ";
		}cout << " �� " << y[i] << endl;
	}
}

void back_sub(double **&U, double *&y, double *&x, unsigned int &n) {
	unsigned int i, j;
	cout << endl << "*********** result of back substitution ************" << endl << endl;
	x[n - 1] = y[n - 1] / U[n - 1][n - 1]; // x[n] (�ڵ忡���� x[n-1])  ���� �̸� ���.
	for (int i = n - 2; i >= 0; i--)
	{
		double c = 0;
		for (j = i + 1; j <= n - 1; j++)
			// back substitution.. �̸� ���� x[n](�ڵ忡���� x[n-1]�� ǥ����) �� ���� ���� 
			// n-1��(�ڵ忡���� n-2������ ǥ����)���� 1�����
			//���ʷ� �����Ͽ� x[n-1], x[n-2]...x[1]�� ���� ���Ѵ�
		{
			c = c + U[i][j] * x[j];
		}
		x[i] = (y[i] - c) / U[i][i];
	}
	for (i = 0; i < n; i++) // back substitution�� ���� ����� x[1~n]�� ������ ���
		cout << "x[" << i + 1 << "]= " << x[i] << endl;

}
void check_soln(double **&A, double *&b, double *&x, unsigned int &n) {
	unsigned int i, j;
	fstream f;
	f.open("���콺(1).txt");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			f >> A[i][j];
		}
	}f.close();
	cout << endl;
	f.open("���콺(2).txt");

	for (i = 0; i < n; i++)
	{
		f >> b[i];
	}
	f.close();

	// A�� b ������, �����ϱ� ���ؼ�
	// ������ ���� �ʰ� �����Ͽ��� ��, Upper tri �� U�� y �� ���� ������ x�� ���Խ��� ����ϴ� ���̱� ������
	// ����� �� ������ �� ���� ����.

	cout << "****************** solution checking ******************" << endl << endl;
	for (i = 0; i < n; i++) {   // error calculation
		double e = 0;
		for (j = 0; j < n; j++) {
			e = e + A[i][j] * x[j];
			cout << " A[" << i + 1 << "]" << "[" << j + 1 << "] * " << "x[" << j + 1 << "]+";
		}cout << "0= " << endl << e << " = " << "b[" << i + 1 << "] = " << endl << b[i] << endl << endl;
		// ���� ����� ������ A��İ� back substitution���� ����� x������ ���� ���� ������ b����� ����� ��ġ�ϸ�
		// �������� ����� �� ��.
	}cout << endl;
}
void delete_mem(double **&A, double *&b, double *&x, double **&U, double *&y, unsigned int &n) {
	for (unsigned int i = 0; i < n; i++)
		delete[] A[i]; // delete all dynamic memory
	delete[] A;
	delete[] b;
	for (unsigned int i = 0; i < n; i++)
		delete[] U[i];
	delete[] U;
	delete[] y;
}
