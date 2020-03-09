// Queen's Attack 2
/*
	체스에서 퀸을 놓았을 때 공격가능한 위치를 모두 출력하기
	장애물을 두면 그 장애물 너머는 공격을 못함

	0 <= n <= 10^5 체스판 n x n
	0 <= k <= 10^5 장애물 갯수
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {	
	// time limit
	/*
	vector<vector<int>> board(n+1);
	for (int i = 0; i < board.size(); i++)
		board[i].resize(n+1);
	for (int i = 0; i < obstacles.size(); i++)
		board[obstacles[i][0]][obstacles[i][1]] = 1;

	int cnt = 0;

	// up
	for (int i = r_q + 1; i <= n; i++) {
		if (board[i][c_q] == 1) break;
		cnt++;
	}
	// down
	for (int i = r_q - 1; i > 0; i--) {
		if (board[i][c_q] == 1) break;
		cnt++;
	}

	// left
	for (int i = c_q - 1; i > 0; i--) {
		if (board[r_q][i] == 1) break;
		cnt++;
	}

	// right
	for (int i = c_q + 1; i <= n; i++) {
		if (board[r_q][i] == 1) break;
		cnt++;
	}

	// left up diagonal
	for (int i = r_q + 1, j = c_q - 1; i <= n && j > 0; i++, j--) {
		if (board[i][j] == 1) break;
		cnt++;
	}

	// right up diagonal
	for (int i = r_q + 1, j = c_q + 1; i <= n && j <= n; i++, j++) {
		if (board[i][j] == 1) break;
		cnt++;
	}

	// left down diagonal
	for (int i = r_q - 1, j = c_q - 1; i > 0 && j > 0; i--, j--) {
		if (board[i][j] == 1) break;
		cnt++;
	}

	// right down diagonal
	for (int i = r_q - 1, j = c_q + 1; i > 0 && j <= n; i--, j++) {
		if (board[i][j] == 1) break;
		cnt++;
	}

	return cnt;
	*/

	// 틀림 뭔가 실수한듯 규칙 찾다가 규칙을 잘못 찾아서 방향이 틀어짐
	/*
	// 퀸과 가장 가까운 장애물
	pair<int, int> up, down, left, right, leftUp, leftDown, rightUp, rightDown;

	up.first = n + 1; up.second = c_q;
	down.first = 0; down.second = c_q;
	left.first = r_q; left.second = 0;
	right.first = r_q; right.second = n + 1;

	if (r_q + c_q <= n + 1) {
		leftUp.first = r_q + c_q; leftUp.second = 0;
		rightDown.first = 0; rightDown.second = r_q + c_q;
	}
	else {
		leftUp.first = n + 1; leftUp.second = r_q + c_q - (n + 1);
		rightDown.first = r_q + c_q - (n + 1); rightDown.second = n + 1;
	}

	if (r_q >= c_q) {
		rightUp.first = n + 1; rightUp.second = n + 1 - (r_q - c_q);
		leftDown.first = r_q - c_q; leftDown.second = 0;
	}
	else {
		rightUp.first = n + 1 - (c_q - r_q); rightUp.second = n + 1;
		leftDown.first = 0; leftDown.second = (c_q - r_q);
	}

	for (vector<int> obstacle : obstacles) {
		int r = obstacle[0], c = obstacle[1];
		// left right == row same
		if (r_q == r) {
			if (c_q > c) left.second = max(left.second, c);
			if (c_q < c) right.second = min(right.second, c);
		}
		// up down == col same
		if (c_q == c) {
			if (r_q > r) down.first = max(down.first, r);
			if (r_q < r) up.first = min(up.first, r);
		}

		// left diagonal = (row+col same)
		if (r_q + c_q == r + c) {
			// leftUp == r_q < r && c_q > c
			if (r_q < r && c_q > c) {
				leftUp.first = min(leftUp.first, r);
				leftUp.second = max(leftUp.second, c);
			}
			// rightDown == r_q > r && c_q < c
			if (r_q > r && c_q < c) {
				rightDown.first = max(rightDown.first, r);
				rightDown.second = min(rightDown.second, c);
			}
		}
		// right diagonal = (abs(row-col) same)
		if (abs(r_q - c_q) == abs(r - c)) {
			// rightUp == r_q < r && c_q < c
			if (r_q < r && c_q < c) {
				rightUp.first = min(rightUp.first, r);
				rightUp.second = min(rightUp.second, c);
			}
			// leftDown == r_q > r && c_q > c
			if (r_q > r && c_q > c) {
				leftDown.first = max(leftDown.first, r);
				leftDown.second = max(leftDown.second, c);
			}
		}
	}

	int cnt = 0;
	// 가로 right - left - 2
	cnt += right.second - left.second - 2;
	// 세로 up - down - 2
	cnt += up.first - down.first - 2;

	// 왼쪽 대각선 leftUp - rightDown => up - down - 2
	cnt += leftUp.first - rightDown.first - 2;
	// 오른쪽 대각선 rightUp - leftDown => up - down - 2
	cnt += rightUp.second - leftDown.second - 2;

	return cnt;
	*/

	set<pair<int, int>> ob;

	for (vector<int> obstacle : obstacles) 
		ob.insert(make_pair(obstacle[0], obstacle[1]));
	
	int dr[] = { -1,1,0,0,-1,1,-1,1, };
	int dc[] = { 0,0,-1,1,-1,1,1,-1 };

	int cnt = 0;

	for (int i = 0; i < 8; i++) {
		int r = r_q + dr[i];
		int c = c_q + dc[i];
		while (true) {
			if (r <= 0 || c <= 0 || r > n || c > n) break;
			if (ob.find(make_pair(r, c)) != ob.end()) break;
			r += dr[i]; c += dc[i];
			cnt++;
		}
	}

	return cnt;
}

int main() {
	int n, k;
	cin >> n >> k;
	int r_q, c_q;
	cin >> r_q >> c_q;
	vector<vector<int>> obstacles(k);
	for (int i = 0; i < k; i++) {
		obstacles[i].resize(2);
		for (int j = 0; j < 2; j++)
			cin >> obstacles[i][j];
	}

	int result = queensAttack(n, k, r_q, c_q, obstacles);
	cout << result << endl;

	return 0;
}