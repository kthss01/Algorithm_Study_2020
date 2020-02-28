// Climbing the Leaderboard
/*
 * dense 밀집한
 * 
 * 스코어가 적힌 리더보드가 있을 때 (배열)
 * 점수를 받았을 때의 랭킹 구하기
 * 
 * 최고점수면 1등
 * 동점이면 같은 등수이고 다음 점수가 바로 다음 등수
 * 
 * ex)
 * 100 90 90 80일때 랭킹 1 2 2 3
 * 70 80 105 점수 획득시 4 3 1
 * 
 * 1 <= n <= 2 x 10^5
 * 1 <= m <= 2 x 10^5
 * 0 <= scores[i] <= 10^9 for 0 <= i < n
 * 0 <= alice[j] <= 10^9 for 0 <= j < m
 * 
 * scores 내림차순
 * alice 오름차순
 * 
 * c++로 풀어서 해결
 */

using System;
using System.Collections.Generic;
using System.Linq;

namespace Climbing_the_Leaderboard
{
    class Solution
    {
        // time limits
        //static int findRank(SortedSet<int> board, int score)
        //{
        //    int rank = 1;

        //    foreach (int boardScore in board)
        //    {
        //        if (boardScore == -score) break;
        //        rank++;
        //    }

        //    return rank;
        //}

        //public static int[] climbingLeaderboard(int[] scores, int[] alice)
        //{
        //    int[] ranks = new int[alice.Length];

        //    SortedSet<int> board = new SortedSet<int>();
        //    foreach (int score in scores)
        //        board.Add(-score);
            
        //    for (int i = 0; i < alice.Length; i++)
        //    {
        //        board.Add(-alice[i]);
        //        ranks[i] = findRank(board, alice[i]);
        //    }

        //    return ranks;
        //}

        // 이렇게 해도 타임 리미트 뜨고 있음
        public static int[] climbingLeaderboard(int[] scores, int[] alice)
        {
            List<int> ranks = new List<int>();
            HashSet<int> board = scores.ToHashSet(); // 중복제거

            int lastScore = board.Last();
            
            foreach(int aliceScore in alice)
            {
                if (lastScore > aliceScore) // aliceScore가 낮으면 마지막 등수
                {
                    lastScore = aliceScore;
                    board.Add(lastScore);
                }
                // lastScore보다 aliceScore가 큰 경우
                else if (lastScore < aliceScore)
                {
                    // lastScore 업데이트
                    while (lastScore < aliceScore)
                    {
                        board.Remove(lastScore); // board에서 마지막 스코어 뺌
                        if (board.Count > 0)
                            lastScore = board.Last();
                        else
                            lastScore = aliceScore;
                    }
                    if (board.Count == 0 || board.Last() != aliceScore)
                    {
                        board.Add(aliceScore);
                        lastScore = aliceScore;
                    }
                }
                ranks.Add(board.Count);
            }

            return ranks.ToArray();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int scoresCount = Convert.ToInt32(Console.ReadLine());
            int[] scores = Array.ConvertAll(Console.ReadLine().Split(' '),
                scoresTemp => Convert.ToInt32(scoresTemp));
            int aliceCount = Convert.ToInt32(Console.ReadLine());
            int[] alice = Array.ConvertAll(Console.ReadLine().Split(' '),
                aliceTemp => Convert.ToInt32(aliceTemp));

            int[] result = Solution.climbingLeaderboard(scores, alice);
            foreach (int ele in result)
                Console.WriteLine(ele);
        }
    }
}
