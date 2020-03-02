#include <iostream>
#include <vector>
#include <algorithm>
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

	// 순열 (next_permutation 함수 이용)
	void Permutation() {
		/*
			중복이 있는 원소들의 경우
			중복인 경우를 제외하고 순열을 만들어줌
		*/
		vector<int> v;
		//for (int i = 0; i < 4; i++)
		//	v.push_back(i + 1);

		v.push_back(0);
		v.push_back(1);
		v.push_back(1);

		sort(v.begin(), v.end());

		// 순열
		do {
			// 출력
			for (int ele : v)
				cout << ele << ' ';
			cout << '\n';
		} while (next_permutation(v.begin(), v.end()));
	}

	// 조합 (next_permutation 함수 이용)
	void Combination() {
		/*
			전체 n개의 원소들 중에서 k개를 뽑는 조합(=nCk)을 구한다면
			n개의 벡터 원소에 1을 k개 0을 나머지인 n-k개 집어넣어서
			순열을 돌리고 1에 해당하는 인덱스만 가져오면 됨
		*/

		// nCk 조합
		int n = 6;
		int k = 4;
		vector<int> v;
		// 1 ~ n까지 생성
		for (int i = 0; i < n; i++)
			v.push_back(i + 1);

		// 0과 1을 저장할 벡터 생성
		vector<int> ind;
		// k개의 1 추가
		for (int i = 0; i < k; i++)
			ind.push_back(1);
		// n-k개의 0 추가
		for (int i = 0; i < v.size() - k; i++)
			ind.push_back(0);

		sort(ind.begin(), ind.end());

		// 순열
		do {
			// 출력
			for (int i = 0; i < ind.size(); i++) {
				if (ind[i] == 1) {
					cout << v[i] << ' ';
				}
			}
			cout << '\n';
		} while (next_permutation(ind.begin(), ind.end()));
	}

	// 곱셈 구현
	class Mul
	{
		void Normalize(vector<int>& num) {
			num.push_back(0);

			// 자릿수 올림 처리
			int size = num.size();
			for (int i = 0; i < size - 1; i++) {
				if (num[i] < 0) {
					int borrow = (abs(num[i]) + 9) / 10;
					num[i + 1] -= borrow;
					num[i] += borrow * 10;
				}
				else {
					num[i + 1] += num[i] / 10;
					num[i] %= 10;
				}
			}
			// 앞에 남은 0 제거
			while (num.size() > 1 && num.back() == 0)
				num.pop_back();
		}
		// 곱셈을 위해 숫자를 벡터로 만들어주는 함수
		vector<int> ToMultVector(long long num) {
			// 뒤집어서 만들어줌 일의 자리부터 연산하므로
			vector<int> v;

			while (num != 0) {
				v.push_back(num % 10);
				num /= 10;
			}

			return v;
		}

	private:
		//카라츠바 알고리즘용
		/*
			수식 수정하면 
			n/2크기의 두 정수의 곱셈 3번, 덧셈 2번, 뺄셈 2번으로 수행 가능
			이를 재귀적으로 처리하여 a1*b1, a()*b()에 대해서도 적용할 수 있음
		*/

		// a += b*(10^k)
		void AddTo(vector<int>& a, const vector<int>& b, int k)
		{
			int originalASize = a.size();
			if (a.size() < b.size() + k)
				a.resize(b.size() + k);
			a.push_back(0);

			int aSize = a.size();
			for (int i = originalASize; i < aSize; i++)
				a[i] = 0;

			int bSize = b.size();

			for (int i = 0; i < bSize; i++)
				a[i + k] += b[i];

			Normalize(a);
		}

		// a -= b
		// a >= b인 경우에만 사용 가능
		void SubFrom(vector<int>& a, const vector<int>& b)
		{
			int bSize = b.size();

			for (int i = 0; i < bSize; i++)
				a[i] -= b[i];

			Normalize(a);
		}

	public:
		// 기본 정수 곱셈
		vector<int> Multiply(long long aNum, long long bNum) {
			vector<int> a = ToMultVector(aNum);
			vector<int> b = ToMultVector(bNum);

			return Multiply(a, b);
		}
		vector<int> Multiply(vector<int> a, vector<int> b)
		{
			/*
			뒤집혀서 a, b로 들어감
			ex)
			a = 24 -> 4, 2 순으로 들어감
			b = 37 -> 7, 3 순으로 들어감
			마지막에 뒤집어 줘야함
			*/

			vector<int> c(a.size() + b.size() + 1, 0);

			int aSize = a.size();
			int bSize = b.size();

			for (int i = 0; i < aSize; i++)
				for (int j = 0; j < bSize; j++)
					c[i + j] += a[i] * b[j];
			Normalize(c);

			return c;
		}

		// 카라츠바 알고리즘
		vector<int> Karatsuba(const vector<int>& a, const vector<int>& b)
		{
			/*
				기본 정수 곱셈이 O(n^2)일 때
				카라츠바 알고리즘은 O(n^log(3))까지 낮춰줌
				log(3) 1.585.. 이므로 n 10만이면 곱셈 횟수 대략 100배 정도 차이
			*/

			int an = a.size(), bn = b.size();

			// a가 b보다 짧을 경우 둘을 바꾼다
			if (an < bn)
				return Karatsuba(b, a);
			// 기저 사례: a나 b가 비어있는 경우
			if (an == 0 || bn == 0)
				return vector<int>();
			// 기저 사례: a가 비교적 짧은 경우, O(n^2) 곱셈으로 변경한다. (성능을 위함)
			if (an <= 50)
				return Multiply(a, b);
			int half = an / 2;

			vector<int> a0(a.begin(), a.begin() + half);
			vector<int> a1(a.begin() + half, a.end());
			vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
			vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

			// z2 = a1 * b1
			vector<int> z2 = Karatsuba(a1, b1);
			
			// z0 = a0 * b0
			vector<int> z0 = Karatsuba(a0, b0);

			// z1 = ((a0+a1) * (b0+b1)) - z0 - z2
			AddTo(a0, a1, 0);
			AddTo(b0, b1, 0);
			vector<int> z1 = Karatsuba(a0, b0);
			SubFrom(z1, z0);
			SubFrom(z1, z2);

			// 병합 과정
			// ret = z0 + z1*10^half + z2*10(half*2)
			vector<int> ret(z2.size() + half * 2, 0);
			AddTo(ret, z0, 0);
			AddTo(ret, z1, half);
			AddTo(ret, z2, half * 2);

			return ret;
		}
	};

	void Multiply(long long a, long long b)
	{
		Mul multi;
		vector<int> c = multi.Multiply(a, b);

		// 다시 뒤집어 주자 출력하기 위해
		reverse(c.begin(), c.end());


		for (int e : c)
			cout << e;
		cout << endl;
	}
	// 카라츠바 알고리즘 테스트
	void Multiply()
	{
		vector<int> a, b;
		for (int i = 0; i < 100; i++)
			a.push_back(i % 10);
		for (int i = 0; i < 73; i++)
			b.push_back(i % 10);

		Mul multi;
		vector<int> c = multi.Karatsuba(a, b);

		// 출력을 위해 뒤집기
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		reverse(c.begin(), c.end());

		cout << "a = ";
		for (int i : a)
			cout << i;
		cout << endl;

		cout << "b = ";
		for (int i : b)
			cout << i;
		cout << endl;

		cout << "a * b = ";
		for (int i : c)
			cout << i;
		cout << endl;
	}
};

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	Algorithm algorithm;

	// gcd 예제
	//int gcd = algorithm.GCD(12, 32);
	//cout << "GCD " << gcd << '\n';

	// 순열 예제
	//algorithm.Permutation();
	
	// 조합 예제
	//algorithm.Combination();

	// 곱셈 예제
	//algorithm.Multiply(1234, 5678);
	algorithm.Multiply();

	return 0;
}