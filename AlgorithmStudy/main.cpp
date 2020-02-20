#include <iostream>
using namespace std;

class Algorithm
{
public:
	// 최대공약수(GCD) 유클리드 알고리즘
	int GCD(int a, int b) {
		/*
			GCD (greatest common divisor)
			유클리드 알고리즘 원리
			임의의 두 자연수 a,b가 주어졌을 때, 둘 중 큰 값이 a라고 가정
			a를 b로 나눈 나머지를 n 이라고 하면 (a%b = n)
			n=0 일때, b가 최대공약수(GCD)
			만약 n이 0이 아니라면, a에 b값을 다시 넣고 n를 b에 대입 한 후 다시 반복
		*/

		//// 반복문 이용
		//int tmp, n;
		//
		//// a에 큰 값 위치
		//if (a < b) {
		//	tmp = a;
		//	a = b;
		//	b = tmp;
		//}

		//// b가 0이 될 때까지(a%b), 반복문, b가 0인 순간 a GCD
		//while (b != 0) {
		//	n = a % b;
		//	a = b;
		//	b = n;
		//}
		//return a;

		// 재귀함수(recursive) 이용
		if (b == 0)
			return a;
		else
			return GCD(b, a % b);
	}

	// 최소공배수(LCM)
	int LCD(int a, int b) {
		/*
			(최소공배수 x 최대공약수 = a x b)를 이용
			a x b / gcd(a,b)
		*/

		return a * b / GCD(a, b);
	}
};

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	Algorithm algorithm;

	// gcd 예제
	int gcd = algorithm.GCD(12, 32);
	cout << "GCD " << gcd << '\n';

	return 0;
}