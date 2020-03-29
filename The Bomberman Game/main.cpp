// The Bomberman Game
/*
	arbitrarily ���Ƿ�
	
	3 5 7 9 11
	2 4 6 8 10
	1 2 3 4 5

	������ ���� ��Ģ
	1. ó���� ������ cell�� ��ź�� ����
	2. 1�� �ƹ��͵� ����
	3. 2�� ������ ������� ��ź�� ����
	4. 3�� ���� ��ź(3�ʸ��� ����) ���� 
		���Ʒ��翷 4�������� ��ź�� ������ �� �� ��ź�� ������
	5. 3,4 �ݺ�
	
	n���� �� ��� ���
	
	1 <= r,c <= 200
	1 <= n <= 10^9
*/

#include <iostream>
#include <vector>
using namespace std;

vector<string> bomberMan(int n, vector<string> grid) {
	vector<string> evenGrid(grid.size());
	
	string even = "";
	for (int i = 0; i < grid[0].size(); i++)
		even += "O";
	for (int i = 0; i < evenGrid.size(); i++) 
		evenGrid[i] = even;
	
	vector<string> oddGrid(evenGrid);

	int rn[] = { -1,1,0,0 };
	int cn[] = { 0,0,-1,1 };

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			if (grid[i][j] == '.') continue;
			oddGrid[i][j] = '.';
			for (int k = 0; k < 4; k++) {
				int r = i + rn[k];
				int c = j + cn[k];
				if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size())
					continue;
				oddGrid[r][c] = '.';
			}
		}
	}

	vector<string> oddGrid2(evenGrid);
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			if (oddGrid[i][j] == '.') continue;
			oddGrid2[i][j] = '.';
			for (int k = 0; k < 4; k++) {
				int r = i + rn[k];
				int c = j + cn[k];
				if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size())
					continue;
				oddGrid2[r][c] = '.';
			}
		}
	}

	if (n % 2 == 0) return evenGrid;
	else if (n == 1) return grid;
	else if (((n - 1)/2) % 2 == 0) return oddGrid2;
	else return oddGrid;
}

int main() {
	int r, c, n;
	cin >> r >> c >> n;

	vector<string> grid(r);

	for (int i = 0; i < r; i++)
		cin >> grid[i];
	
	vector<string> result = bomberMan(n, grid);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i];

		if (i != result.size())
			cout << '\n';
	}
	cout << endl;

	return 0;
}