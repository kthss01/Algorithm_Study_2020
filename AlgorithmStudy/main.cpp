// ��ü �����/���̱�: Ctrl+MO, Ctrl+ML
// ������ �κ��� �����: Ctrl+MH

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Algorithm
{
public:
	// �ִ�����(GCD) ��Ŭ���� �˰���
	int GCD(int a, int b) {
		/*
			GCD (greatest common divisor)
			��Ŭ���� �˰��� ����
			������ �� �ڿ��� a,b�� �־����� ��, �� �� ū ���� a��� ����
			a�� b�� ���� �������� n �̶�� �ϸ� (a%b = n)
			n=0 �϶�, b�� �ִ�����(GCD)
			���� n�� 0�� �ƴ϶��, a�� b���� �ٽ� �ְ� n�� b�� ���� �� �� �ٽ� �ݺ�
		*/

		//// �ݺ��� �̿�
		//int tmp, n;
		//
		//// a�� ū �� ��ġ
		//if (a < b) {
		//	tmp = a;
		//	a = b;
		//	b = tmp;
		//}

		//// b�� 0�� �� ������(a%b), �ݺ���, b�� 0�� ���� a GCD
		//while (b != 0) {
		//	n = a % b;
		//	a = b;
		//	b = n;
		//}
		//return a;

		// ����Լ�(recursive) �̿�
		if (b == 0)
			return a;
		else
			return GCD(b, a % b);
	}

	// �ּҰ����(LCM)
	int LCD(int a, int b) {
		/*
			(�ּҰ���� x �ִ����� = a x b)�� �̿�
			a x b / gcd(a,b)
		*/

		return a * b / GCD(a, b);
	}

	// ���� (next_permutation �Լ� �̿�)
	void Permutation() {
		///*
		//	�ߺ��� �ִ� ���ҵ��� ���
		//	�ߺ��� ��츦 �����ϰ� ������ �������
		//*/
		//vector<int> v;
		////for (int i = 0; i < 4; i++)
		////	v.push_back(i + 1);

		//v.push_back(0);
		//v.push_back(1);
		//v.push_back(1);

		//sort(v.begin(), v.end());

		//// ����
		//do {
		//	// ���
		//	for (int ele : v)
		//		cout << ele << ' ';
		//	cout << '\n';
		//} while (next_permutation(v.begin(), v.end()));

		//cout << endl;
		//
		//// ���� ����
		//vector<int> arr = { 1, 2, 3 };
		////PermutationSelf(arr, 0, arr.size()-1);
		//HeapPermutation(arr, arr.size());

		// ������ ���� ���� ����
		vector<int> arr = { 1,2,3,4 };
		do 
		{
			for (int ele : arr)
				cout << ele << ' ';
			cout << endl;
		} while (NextPermutation(arr));

	}

	// ���� ����
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

	// �� �˰���
	void HeapPermutation(vector<int>& arr, int size)
	{
		//  ����� 1�̸� arr ���
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
			// ��� �Լ� ȣ��
			HeapPermutation(arr, size - 1);

			if (i < size - 1)
			{
				// ������ Ȧ���� ù��° ������ ����
				if (size % 2 == 1)
					swap(arr[0], arr[size - 1]);
				// ������ ¦���� i��°�� ������ ����
				else
					swap(arr[i], arr[size - 1]);
			}
		}
	}

	// ������ ���� ���� ����
	bool NextPermutation(vector<int>& arr) {
		/*
			c++ next_permutation ���� �׳� ������ �̿� �����ϴ°� �����غ������
			14���� �ε��� ������ ����߳� �ǵ�Ÿ�� ����ߴٰ� ��

			1. a[k] < a[k+1]�� ���� ū �ε��� k ã��
			���� �̸� ã�� �� ���ٸ�, ������ �������� ���ĵ� ������ 
			������ ������ �� ������ ���� ��
			2. k�� ã�Ҵٸ� k ������ �ε������� a[k]���� ū ���� ����
			���� �� �ε��� l�� ã��
			3. k l ��ġ�� �� ��ȯ
			4. �׷� ���� k���� ���� ��ġ�� ���鸸 �������� ���ġ

			ex) 4,1,5,3,2
			1. �����ϴ� ������ �ε��� 1 (a[1] => 1)
			2. 1���� ū ���� ������ ���� �� �ε����� 4 (a[4] >= 2)
			3. 1�� 4 �ڸ��� �� ��ȯ ([4,2,5,3,1])
			4. 1 ������ 3�� ���� �������� �����´� ([4,2,1,3,5])
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

	// ���� (next_permutation �Լ� �̿�)
	void Combination() {
		/*
			��ü n���� ���ҵ� �߿��� k���� �̴� ����(=nCk)�� ���Ѵٸ�
			n���� ���� ���ҿ� 1�� k�� 0�� �������� n-k�� ����־
			������ ������ 1�� �ش��ϴ� �ε����� �������� ��
		*/

		// nCk ����
		int n = 6;
		int k = 4;
		vector<int> v;
		// 1 ~ n���� ����
		for (int i = 0; i < n; i++)
			v.push_back(i + 1);

		// 0�� 1�� ������ ���� ����
		vector<int> ind;
		// k���� 1 �߰�
		for (int i = 0; i < k; i++)
			ind.push_back(1);
		// n-k���� 0 �߰�
		for (int i = 0; i < v.size() - k; i++)
			ind.push_back(0);

		sort(ind.begin(), ind.end());

		// ����
		do {
			// ���
			for (int i = 0; i < ind.size(); i++) {
				if (ind[i] == 1) {
					cout << v[i] << ' ';
				}
			}
			cout << '\n';
		} while (next_permutation(ind.begin(), ind.end()));
	}

	// ���� ����
	class Mul
	{
		void Normalize(vector<int>& num) {
			num.push_back(0);

			// �ڸ��� �ø� ó��
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
			// �տ� ���� 0 ����
			while (num.size() > 1 && num.back() == 0)
				num.pop_back();
		}
		// ������ ���� ���ڸ� ���ͷ� ������ִ� �Լ�
		vector<int> ToMultVector(long long num) {
			// ����� ������� ���� �ڸ����� �����ϹǷ�
			vector<int> v;

			while (num != 0) {
				v.push_back(num % 10);
				num /= 10;
			}

			return v;
		}

	private:
		//ī������ �˰����
		/*
			���� �����ϸ� 
			n/2ũ���� �� ������ ���� 3��, ���� 2��, ���� 2������ ���� ����
			�̸� ��������� ó���Ͽ� a1*b1, a()*b()�� ���ؼ��� ������ �� ����
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
		// a >= b�� ��쿡�� ��� ����
		void SubFrom(vector<int>& a, const vector<int>& b)
		{
			int bSize = b.size();

			for (int i = 0; i < bSize; i++)
				a[i] -= b[i];

			Normalize(a);
		}

	public:
		// �⺻ ���� ����
		vector<int> Multiply(long long aNum, long long bNum) {
			vector<int> a = ToMultVector(aNum);
			vector<int> b = ToMultVector(bNum);

			return Multiply(a, b);
		}
		vector<int> Multiply(vector<int> a, vector<int> b)
		{
			/*
			�������� a, b�� ��
			ex)
			a = 24 -> 4, 2 ������ ��
			b = 37 -> 7, 3 ������ ��
			�������� ������ �����
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

		// ī������ �˰���
		vector<int> Karatsuba(const vector<int>& a, const vector<int>& b)
		{
			/*
				�⺻ ���� ������ O(n^2)�� ��
				ī������ �˰����� O(n^log(3))���� ������
				log(3) 1.585.. �̹Ƿ� n 10���̸� ���� Ƚ�� �뷫 100�� ���� ����
			*/

			int an = a.size(), bn = b.size();

			// a�� b���� ª�� ��� ���� �ٲ۴�
			if (an < bn)
				return Karatsuba(b, a);
			// ���� ���: a�� b�� ����ִ� ���
			if (an == 0 || bn == 0)
				return vector<int>();
			// ���� ���: a�� ���� ª�� ���, O(n^2) �������� �����Ѵ�. (������ ����)
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

			// ���� ����
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

		// �ٽ� ������ ���� ����ϱ� ����
		reverse(c.begin(), c.end());


		for (int e : c)
			cout << e;
		cout << endl;
	}
	// ī������ �˰��� �׽�Ʈ
	void Multiply()
	{
		vector<int> a, b;
		for (int i = 0; i < 100; i++)
			a.push_back(i % 10);
		for (int i = 0; i < 73; i++)
			b.push_back(i % 10);

		Mul multi;
		vector<int> c = multi.Karatsuba(a, b);

		// ����� ���� ������
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

	// Union Find �˰��� (Disjoint-Set(���μ� ����) �˰���)
	struct NaiveDisjointSet {
		/* 
			�־��� ��� ������ ���Ī���� Ʈ��, �� ���Ḯ��Ʈ ���°� �Ǿ���� �� ����
			�̷��� �Ǹ� Union, Find ���� ����ð��� O(N)�� �Ǿ���� ȿ���� ������
		*/
		vector<int> parent;
		NaiveDisjointSet(int n) : parent(n) {
			// �ʱ�ȭ
			for (int i = 0; i < n; i++)
				parent[i] = i;
		}

		// Find (ã��) ����
		// u�� ���� Ʈ���� ��Ʈ ��� ��ȣ�� ��ȯ�Ѵ�.
		int find(int u) const {
			// ��Ʈ ���� �θ� ��� ��ȣ�� �ڱ� �ڽ��� ������.
			if (u == parent[u]) return u;
			
			// �� ����� �θ� ��带 ã�� �ö󰣴�.
			return find(parent[u]);
		}

		// Union(��ġ��) ����
		// u�� ���� Ʈ���� v�� ���� Ʈ���� ��ģ��
		void merge(int u, int v) {
			// �� ���Ұ� ���� Ʈ���� ��Ʈ ��带 ã�´�.
			u = find(u); v = find(v);

			// u�� v�� �̹� ���� Ʈ���� ���ϴ� ��쿡�� ��ġ�� �ʴ´�.
			if (u == v) return;
			parent[u] = v;
		}

	};

	// disjoint set ����ȭ (union-by-rank)
	struct OptimizedDisjointSet {
		/*
			�� Ʈ���� �պ��� ��, �׻� ���̰� �� ���� Ʈ���� �� ���� Ʈ�� �ؿ� ����ִ´�.
			rank�� Ʈ���� ���̸� ����
			�� Ʈ���� rank�� �����Ͽ� ���̰� �������䳪 �ϴ� ��쿡��
			���� �� ��� Ʈ���� rank�� 1 ���� ���� �ش�.

			����ȭ�� ���� Union�� Find ������ �ð����⵵�� O(lgN)�� �ȴ�.
		*/

		vector<int> parent, rank;
		OptimizedDisjointSet(int n) : parent(n), rank(n, 1) {
			for (int i = 0; i < n; i++)
				parent[i] = i;
		}

		int find(int u) {
			if (u == parent[u]) return u;

			// ��� ���� (path compression)
			/*
				parent�� ã�Ƴ� ��Ʈ�� �ƿ� �ٲ� ������ 
				find ���� ����� �ߺ��Ǵ� ������ �ٿ��ش�.
			*/
			return parent[u] = find(parent[u]);
		}

		void merge(int u, int v) {
			u = find(u); v = find(v);

			if (u == v) return;

			if (rank[u] > rank[v]) swap(u, v);
			parent[u] = v;
			// �� Ʈ���� ���̰� ���� ��쿡�� ��� Ʈ���� rank�� 1 �����ش�.
			if (rank[u] == rank[v]) rank[v]++;
		}
	};

	void UnionFind() {
		//NaiveDisjointSet set(11);
		OptimizedDisjointSet set(11);

		/*
			ex)
			0 1234 5678 910 ǥ��
		*/
		set.merge(1, 2);
		set.merge(2, 3);
		set.merge(3, 4);
		set.merge(5, 6);
		set.merge(6, 7);
		set.merge(7, 8);
		set.merge(9, 10);
		
		if (set.find(1) == set.find(5)) cout << "1�� 5�� ����Ǿ�����" << endl;
		else cout << "1�� 5�� ����Ǿ� ���� ����" << endl;
		if (set.find(1) == set.find(3)) cout << "1�� 3�� ����Ǿ�����" << endl;
		else cout << "1�� 3�� ����Ǿ� ���� ����" << endl;
		if (set.find(5) == set.find(10)) cout << "1�� 5�� ����Ǿ�����" << endl;
		else cout << "5�� 10�� ����Ǿ� ���� ����" << endl;
	}

	// CCW�� �̿��� ���� ���� �Ǻ�
	/*
		���� ccw �Լ��� ��ȯ�ϴ� ���� ������ �����, 2�� �����شٸ� �� ���� �̷��
		�ﰢ���� ���̸� ���� �� ����
		ccw ���ϴ°� ������ �ﰢ���� ���� ���ϴµ� ���̴� �缱 ������ �̿��ϰ� �Ǳ� ����
	*/
	int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
		/*
			0���� ũ�� �ݽð� ����
			0���� ������ �ð� ����
			0�̸� ���� ����
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

		// �������� ���� ���
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

	// gcd ����
	//int gcd = algorithm.GCD(12, 32);
	//cout << "GCD " << gcd << '\n';

	// ���� ����
	algorithm.Permutation();

	// ���� ����
	//algorithm.Combination();

	// ���� ����
	//algorithm.Multiply(1234, 5678);
	//algorithm.Multiply();

	// Union-Find �˰��� ����
	//algorithm.UnionFind();

	return 0;
}