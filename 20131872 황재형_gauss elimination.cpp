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
	for (unsigned int i = 0; i < n; i++)//n행n열
		A[i] = new double[n];
	b = new double[n];
	x = new double[n];

	U = new double *[n]; //allocate dynamic memory
	for (unsigned int i = 0; i < n; i++)//n행n열
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
	cout.precision(15); // 소수점 15째 자리까지 읽기
						//*************** txt file 로부터 숫자 읽어들이기*****************
	f.open("가우스(1).txt"); // n*n개의 숫자가 입력되어있는 txt파일의 이름
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			f >> A[i][j]; // 읽어들이기
		}
	}f.close();
	cout << endl;
	f.open("가우스(2).txt"); // n개의 숫자가 입력되어 있는 txt 파일의 이름
	for (i = 0; i < n; i++)
	{
		f >> b[i]; //읽어들이기
	}
	f.close();
	cout << "************* read A & b from txt.file **************" << endl << endl;
	cout << "A[i][j]ㅣ b[i]" << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout << A[i][j] << " ";  // n행 n열 A 출력
		}
		cout << " ㅣ " << b[i] << endl; // n행 1열 b 출력
	}cout << endl;
	// 예를 들어 2x+3y=1, 4x+6y=2일 경우, 1행1열에 2, 1행2열에 3, 2행 1열에 4, 2행 2열에 6을 표시한 행렬 1개와
	// 1행1열에 1, 2행 1열에 2 를 나타내는 행렬 1개를 두어 각각 방정식의 계수와 해를 행렬로 표현.
	//  "ㅣ" 오른쪽에 해의 값을 표시.

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
	} // 예를들어 A의 1행1열과(코드에서는 0행0열로 표현됨) A의 2행 1열을 비교하였을 때,
	  //A의 2행 1열이 더 크다면 A의 1행 1열과 2행1열, 1행 2열과 2행2열...을 n행 까지 모두 바꾸어준다.
	  // 또한 b의 1행과 2행을 바꾸어줌을 반복함으로써, 각 기준점에 가장 큰 숫자가 놓일 수 있도록 한다.

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout << A[i][j] << " ";
		}cout << "ㅣ" << b[i] << endl;
	}
	

	for (k = 0; k < n - 1; k++)
		for (i = k; i < n - 1; i++)
		{
			double c = (A[i + 1][k] / A[k][k]); //upper triangular 과정.
			b[i + 1] -= c*b[k];   // 예를 들어서, 2행1열을 1행1열(여기서는 0행0열로 표현되어있음)로 나눈 값을 c라고 하면
			for (j = 0; j < n; j++)// 우선 b행렬의 2행1열에서 1행1열에 c를 곱한 값을 뺀다.
				A[i + 1][j] -= c*A[k][j];// 또한 A행렬의 2행 1열에 1행 1열에 c를 곱한 값을 저장,
		}                                   // 마찬가지로 2행 2열에 1행 2열에 c를 곱한 값을 뺀 값을 저장하며 n열까지 반복한다.(코드에서는 n-1열이다)

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			U[i][j] = A[i][j];  // upper tri 한 결과를 U행렬(n by n array)에 할당한다
			y[i] = b[i];       // 마찬가지로 b행렬의 결과를 y 행렬에 저장한다.
		}
	}

	cout << "****************** upper triangular ******************" << endl;
	cout << endl << "U[i][j]   ㅣ y[i]" << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) { // upper tri 한 결과를 출력(U[i][j] , y[i][j])
			cout << U[i][j] << "  ";
		}cout << " ㅣ " << y[i] << endl;
	}
}

void back_sub(double **&U, double *&y, double *&x, unsigned int &n) {
	unsigned int i, j;
	cout << endl << "*********** result of back substitution ************" << endl << endl;
	x[n - 1] = y[n - 1] / U[n - 1][n - 1]; // x[n] (코드에서는 x[n-1])  값을 미리 계산.
	for (int i = n - 2; i >= 0; i--)
	{
		double c = 0;
		for (j = i + 1; j <= n - 1; j++)
			// back substitution.. 미리 구한 x[n](코드에서는 x[n-1]로 표현됨) 의 값을 토대로 
			// n-1행(코드에서는 n-2행으로 표현됨)부터 1행까지
			//차례로 대입하여 x[n-1], x[n-2]...x[1]의 값을 구한다
		{
			c = c + U[i][j] * x[j];
		}
		x[i] = (y[i] - c) / U[i][i];
	}
	for (i = 0; i < n; i++) // back substitution을 토대로 계산한 x[1~n]의 값들을 출력
		cout << "x[" << i + 1 << "]= " << x[i] << endl;

}
void check_soln(double **&A, double *&b, double *&x, unsigned int &n) {
	unsigned int i, j;
	fstream f;
	f.open("가우스(1).txt");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			f >> A[i][j];
		}
	}f.close();
	cout << endl;
	f.open("가우스(2).txt");

	for (i = 0; i < n; i++)
	{
		f >> b[i];
	}
	f.close();

	// A와 b 재정의, 검증하기 위해서
	// 재정의 하지 않고 검증하였을 시, Upper tri 된 U와 y 의 값을 가지고 x를 대입시켜 계산하는 것이기 때문에
	// 제대로 된 검증을 할 수가 없음.

	cout << "****************** solution checking ******************" << endl << endl;
	for (i = 0; i < n; i++) {   // error calculation
		double e = 0;
		for (j = 0; j < n; j++) {
			e = e + A[i][j] * x[j];
			cout << " A[" << i + 1 << "]" << "[" << j + 1 << "] * " << "x[" << j + 1 << "]+";
		}cout << "0= " << endl << e << " = " << "b[" << i + 1 << "] = " << endl << b[i] << endl << endl;
		// 원래 출력한 최초의 A행렬과 back substitution으로 계산한 x값들을 곱한 값이 최초의 b행렬의 값들과 일치하면
		// 오류없이 계산이 된 것.
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
