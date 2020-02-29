// The Hurdle Race
/*
 * hurdle 높이가 배열로 주어질 때 기본이 점프가 주어질 때 
 * 몇이 더 높아야 다 뛰어 넘을 수 있는지 알기
 * 
 * 1 <= n, k <= 100
 * 1 <= height[i] <= 100
 */

using System;

namespace The_Hurdle_Race
{
    class Solution
    {
        static public int hurdleRace(int k, int[] height)
        {
            int maxHeight = 0;
            foreach (int h in height)
                maxHeight = Math.Max(maxHeight, h);

            return maxHeight > k ? maxHeight - k : 0;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            string[] nk = Console.ReadLine().Split(' ');
            int n = Convert.ToInt32(nk[0]);
            int k = Convert.ToInt32(nk[1]);

            int[] height = Array.ConvertAll(Console.ReadLine().Split(' '),
                heightTemp => Convert.ToInt32(heightTemp));

            int result = Solution.hurdleRace(k, height);

            Console.WriteLine(result);
        }
    }
}
