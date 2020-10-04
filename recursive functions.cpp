#include<iostream>
using namespace std;
int hanoi_total_steps(int n);
void hanoi_steps(int n, char a, char b, char c) {
	if (n == 1)
		cout << "move " << n << " from " << a << " to " << b << endl;
	else
	{
		hanoi_steps(n - 1, a, c, b);//moving towers except bottom to spare place
		cout << "move " << n << " from " << a << " to " << b << endl;//moving bottom tower to b
		hanoi_steps(n - 1, c, b, a);//moving towers except bottom to b
	}
}
int hanoi_total_steps(int n) //recursive function of solving total steps needed
{
	if (n == 1)
		return 1;
	else
		return hanoi_total_steps(n - 1) * 2 + 1;
	/* number of steps when towers are n, it should be steps when (n-1)*2+1
	because if we just simplify think, number of (n-1)towers should be moved to other, and last
	tower should move , and then number of (n-1) towers should be moved on the largest tower*/
}
int main() {
	int n = 4;//n=4 for recursive function
	cout << "number of towers are 4" << endl;
	cout << "show me the steps" << endl;
	hanoi_steps(n, 'a', 'b', 'c');
	cout << "how many total steps are needed?" << endl;
	cout << hanoi_total_steps(n) << endl; // using recursive function
}
