// C#으로 풀려했는데 몇몇 테스트 케이스가 시간초과 났었음
// 그래서 c++로 푸니 해결됨

#include <iostream>
#include <vector>
using namespace std;

vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
	vector<int> ranks;

	vector<int> board;
	for (int i = 0; i < scores.size(); i++) {
		if (i == 0) board.push_back(scores[i]);
		else if (board.back() != scores[i])
			board.push_back(scores[i]);
	}

	for (int aliceScore : alice) {
		int lastScore = board.back();

		if (lastScore > aliceScore) {
			board.push_back(aliceScore);
		}
		else if (lastScore < aliceScore) {
			while (lastScore < aliceScore) {
				board.pop_back();
				if (board.size() > 0)
					lastScore = board.back();
				else
					lastScore = aliceScore;
			}
			if (board.size() == 0 || board.back() != aliceScore)
			{
				board.push_back(aliceScore);
			}
		}
		ranks.push_back(board.size());
	}

	return ranks;
}

int main() {
	
	int scores_count;
	cin >> scores_count;
	vector<int> scores(scores_count);
	for (int i = 0; i < scores_count; i++)
		cin >> scores[i];

	int alice_count;
	cin >> alice_count;
	vector<int> alice(alice_count);
	for (int i = 0; i < alice_count; i++)
		cin >> alice[i];

	vector<int> result = climbingLeaderboard(scores, alice);

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << '\n';

	return 0;
}