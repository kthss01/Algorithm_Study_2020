// ACM ICPC Team
/*
 * 각 팀이 문제를 푸는게 주어질 때
 * 2팀이 최대한 문제를 많이 풀 수 있는 경우를 구하고
 * 그 문제를 몇 팀까지 풀 수 있는지 구하기
 * 
 * ex)
 * 10101
 * 11110
 * 00010
 * 
 * (1,2) [1,2,3,4,5] -> 이 경우가 가장 많이 품 그리고 1팀만 간으
 * (1,3) [1,3,4,5]
 * (2,3) [1,2,3,4]
 * => 5 1
 * 
 * 2 <= n <= 500 팀 수
 * 1 <= m <= 500 문제 수
 */

using System;

namespace ACM_ICPC_Team
{
    class Program
    {
        static int[] acmTeam(string[] topic)
        {
            int[] topics = new int[topic[0].Length];

            int maxTopics = 0;

            for(int i=0; i<topic.Length-1; i++)
            {
                for(int j=i+1; j<topic.Length; j++)
                {
                    int topicNum = 0;

                    for(int k=0; k<topic[0].Length; k++)
                    {
                        if (topic[i][k] == '1' || topic[j][k] == '1')
                            topicNum++;
                    }

                    maxTopics = Math.Max(topicNum, maxTopics);

                    if (topicNum != 0)
                        topics[topicNum - 1]++; 
                }
            }

            return new int[] { maxTopics, topics[maxTopics-1] };
        }

        static void Main(string[] args)
        {
            string[] nm = Console.ReadLine().Split(' ');
            int n = Convert.ToInt32(nm[0]);
            int m = Convert.ToInt32(nm[1]);

            string[] topic = new string[n];
            for(int i=0; i<n; i++)
            {
                string topicTeam = Console.ReadLine();
                topic[i] = topicTeam;
            }

            int[] result = acmTeam(topic);

            Console.WriteLine(string.Join("\n", result));
        }
    }
}
