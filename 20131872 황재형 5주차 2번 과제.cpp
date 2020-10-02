/*자연수 n이 소수인지 아닌지를 판정하려면,
2≤p≤ √n인 범위에 있는 모든 소수 p로 n을 나누어 보아,
나누어 떨어지지 않으면 소수이고, 나누어 떨어지면 합성수이다
출처 :[네이버 지식백과] 소수[prime number, 素數](두산백과)*/
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