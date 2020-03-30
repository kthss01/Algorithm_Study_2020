// 전체 숨기기/보이기: Ctrl+MO, Ctrl+ML
// 선택한 부분을 숨기기: Ctrl+MH

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
		///*
		//	중복이 있는 원소들의 경우
		//	중복인 경우를 제외하고 순열을 만들어줌
		//*/
		//vector<int> v;
		////for (int i = 0; i < 4; i++)
		////	v.push_back(i + 1);

		//v.push_back(0);
		//v.push_back(1);
		//v.push_back(1);

		//sort(v.begin(), v.end());

		//// 순열
		//do {
		//	// 출력
		//	for (int ele : v)
		//		cout << ele << ' ';
		//	cout << '\n';
		//} while (next_permutation(v.begin(), v.end()));

		//cout << endl;
		//
		//// 직접 구현
		//vector<int> arr = { 1, 2, 3 };
		////PermutationSelf(arr, 0, arr.size()-1);
		//HeapPermutation(arr, arr.size());

		// 사전식 순열 생성 구현
		vector<int> arr = { 1,2,3,4 };
		do 
		{
			for (int ele : arr)
				cout << ele << ' ';
			cout << endl;
		} while (NextPermutation(arr));

	}

	// 순열 구현
	void PermutationSelf(vector<int>& arr, int start, int end)
	{
		if (start == end) {
			for (auto it : arr)
				cout << it << " ";
			cout << endl;
		}
		else {
			for (int i = start; i <= end; i++) {
				swap(arr[start], arr[i]);
				PermutationSelf(arr, start + 1, end);
				swap(arr[start], arr[i]);
			}
		}
	}

	// 힙 알고리즘
	void HeapPermutation(vector<int>& arr, int size)
	{
		//  사이즈가 1이면 arr 출력
		if (size == 1)
		{
			for (const auto it : arr)
			{
				cout << it << " ";
			}
			cout << endl;
			return;
		}

		for (int i = 0; i < size; i++)
		{
			// 재귀 함수 호출
			HeapPermutation(arr, size - 1);

			if (i < size - 1)
			{
				// 사이즈 홀수면 첫번째 마지막 스왑
				if (size % 2 == 1)
					swap(arr[0], arr[size - 1]);
				// 사이즈 짝수면 i번째와 마지막 스왑
				else
					swap(arr[i], arr[size - 1]);
			}
		}
	}

	// 사전식 순열 생성 구현
	bool NextPermutation(vector<int>& arr) {
		/*
			c++ next_permutation 쓰면 그냥 되지만 이왕 공부하는거 구현해보기로함
			14세기 인도의 수학자 나라야나 판디타가 고안했다고 함

			1. a[k] < a[k+1]인 가장 큰 인덱스 k 찾기
			만약 이를 찾을 수 없다면, 수열이 역순으로 정렬된 것으로 
			사전식 순열의 맨 마지막 항이 됨
			2. k를 찾았다면 k 이후의 인덱스에서 a[k]보다 큰 값을 가진
			가장 먼 인덱스 l를 찾기
			3. k l 위치의 값 교환
			4. 그런 다음 k보다 다음 위치의 값들만 역순으로 재배치

			ex) 4,1,5,3,2
			1. 증가하는 마지막 인덱스 1 (a[1] => 1)
			2. 1보다 큰 값을 가지는 가장 먼 인덱스는 4 (a[4] >= 2)
			3. 1과 4 자리의 값 교환 ([4,2,5,3,1])
			4. 1 다음의 3개 숫자 역순으로 뒤집는다 ([4,2,1,3,5])
		*/

		// Find logest non-increasing suffix
		int i = arr.size() - 1;
		while (i > 0 && arr[i - 1] >= arr[i]) i--;
		// Now i is the head index of the suffix

		if (i <= 0) return false;

		// arr[i-1] be the pivot
		// Find rightmost element that exceeds the pivot
		int j = arr.size() - 1;
		while (arr[j] <= arr[i - 1]) j--;
		// arr[j] new pivto
		// Assertion: j >= i

		// swap pivot j
		int temp = arr[i - 1];
		arr[i - 1] = arr[j];
		arr[j] = temp;

		// reverse the suffix
		j = arr.size() - 1;
		while (i < j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}

		return true;
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

	// Union Find 알고리즘 (Disjoint-Set(서로소 집합) 알고리즘)
	struct NaiveDisjointSet {
		/* 
			최악의 경우 완전히 비대칭적인 트리, 즉 연결리스트 형태가 되어버릴 수 있음
			이렇게 되면 Union, Find 연산 수행시간이 O(N)이 되어버려 효율이 나빠짐
		*/
		vector<int> parent;
		NaiveDisjointSet(int n) : parent(n) {
			// 초기화
			for (int i = 0; i < n; i++)
				parent[i] = i;
		}

		// Find (찾기) 연산
		// u가 속한 트리의 루트 노드 번호를 반환한다.
		int find(int u) const {
			// 루트 노드는 부모 노드 번호로 자기 자신을 가진다.
			if (u == parent[u]) return u;
			
			// 각 노드의 부모 노드를 찾아 올라간다.
			return find(parent[u]);
		}

		// Union(합치기) 연산
		// u가 속한 트리와 v가 속한 트리를 합친다
		void merge(int u, int v) {
			// 각 원소가 속한 트리의 루트 노드를 찾는다.
			u = find(u); v = find(v);

			// u와 v가 이미 같은 트리에 속하는 경우에는 합치지 않는다.
			if (u == v) return;
			parent[u] = v;
		}

	};

	// disjoint set 최적화 (union-by-rank)
	struct OptimizedDisjointSet {
		/*
			두 트리를 합병할 때, 항상 높이가 더 낮은 트리를 더 높은 트리 밑에 집어넣는다.
			rank에 트리의 높이를 저장
			두 트리의 rank가 동일하여 높이가 높아져얌나 하는 경우에는
			합형 후 결과 트리의 rank를 1 증가 시켜 준다.

			최적화를 통해 Union과 Find 연산의 시간복잡도가 O(lgN)이 된다.
		*/

		vector<int> parent, rank;
		OptimizedDisjointSet(int n) : parent(n), rank(n, 1) {
			for (int i = 0; i < n; i++)
				parent[i] = i;
		}

		int find(int u) {
			if (u == parent[u]) return u;

			// 경로 압축 (path compression)
			/*
				parent를 찾아낸 루트로 아예 바꿔 버리면 
				find 연산 수행시 중복되는 연산을 줄여준다.
			*/
			return parent[u] = find(parent[u]);
		}

		void merge(int u, int v) {
			u = find(u); v = find(v);

			if (u == v) return;

			if (rank[u] > rank[v]) swap(u, v);
			parent[u] = v;
			// 두 트리의 높이가 같은 경우에는 결과 트리의 rank를 1 높여준다.
			if (rank[u] == rank[v]) rank[v]++;
		}
	};

	void UnionFind() {
		//NaiveDisjointSet set(11);
		OptimizedDisjointSet set(11);

		/*
			ex)
			0 1234 5678 910 표현
		*/
		set.merge(1, 2);
		set.merge(2, 3);
		set.merge(3, 4);
		set.merge(5, 6);
		set.merge(6, 7);
		set.merge(7, 8);
		set.merge(9, 10);
		
		if (set.find(1) == set.find(5)) cout << "1과 5는 연결되어있음" << endl;
		else cout << "1과 5는 연결되어 있지 않음" << endl;
		if (set.find(1) == set.find(3)) cout << "1과 3은 연결되어있음" << endl;
		else cout << "1과 3은 연결되어 있지 않음" << endl;
		if (set.find(5) == set.find(10)) cout << "1과 5는 연결되어있음" << endl;
		else cout << "5와 10은 연결되어 있지 않음" << endl;
	}

	// CCW를 이용한 선분 교차 판별
	/*
		참고 ccw 함수에 반환하는 값에 절댓값을 씌우고, 2로 나눠준다면 세 점이 이루는
		삼각형의 넓이를 구할 수 있음
		ccw 구하는게 외적과 삼각형의 넓이 구하는데 쓰이는 사선 공식을 이용하게 되기 때문
	*/
	int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
		/*
			0보다 크면 반시계 방향
			0보다 작으면 시계 방향
			0이면 세점 평행
		*/
		int op = a.first * b.second + b.first * c.second + c.first * a.second;
		op -= (a.second * b.first + b.second * c.first + c.second * a.first);
		
		if (op > 0) return 1;
		else if (op == 0) return 0;
		else return -1;
	}

	int IsIntersect(pair<pair<int, int>, pair<int, int>> x, pair<pair<int, int>, pair<int, int>> y) {
		pair<int, int> a = x.first;
		pair<int, int> b = x.second;
		pair<int, int> c = y.first;
		pair<int, int> d = y.second;
		int ab = ccw(a, b, c) * ccw(a, b, d);
		int cd = ccw(c, d, a) * ccw(c, d, b);

		// 일직선상에 놓인 경우
		if (ab == 0 && cd == 0) {
			if (a > b) swap(a, b);
			if (c > d) swap(c, d);
			return c <= b && a <= d;
		}
		return ab <= 0 && cd <= 0;
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
	algorithm.Permutation();

	// 조합 예제
	//algorithm.Combination();

	// 곱셈 예제
	//algorithm.Multiply(1234, 5678);
	//algorithm.Multiply();

	// Union-Find 알고리즘 예제
	//algorithm.UnionFind();

	return 0;
}