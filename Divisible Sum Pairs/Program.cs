// Divisible Sum Pairs
/*
 * 배열과 숫자 k가 있는데
 * (i,j)쌍의 (i < j) 합이 k로 나눠지는 쌍을 찾기
 * 
 * ex)
 * ar = [1,2,3,4,5,6], k = 5
 * [1,4], [2,3], [4,6]
 * 
 * 2 <= n <= 100
 * 1 <= k <= 100
 * 1 <= ar[i] <= 100
 * 
 * 갯수 출력
 */

using System;

namespace Divisible_Sum_Pairs
{
    class Program
    {
        static int divisibleSumPairs(int n, int k, int[] ar)
        {
            int count = 0;

            for(int i=0; i<n; i++)
            {
                for(int j=i+1; j<n; j++)
                {
                    if ((ar[i] + ar[j]) % k == 0)
                        count++;
                }
            }

            return count;
        }

        static void Main(string[] args)
        {
            string[] nk = Console.ReadLine().Split(' ');
            int n = Convert.ToInt32(nk[0]);
            int k = Convert.ToInt32(nk[1]);

            int[] ar = Array.ConvertAll(Console.ReadLine().Split(' '),
                arTemp => Convert.ToInt32(arTemp));

            int result = divisibleSumPairs(n, k, ar);
            Console.WriteLine(result);
        }
    }
}
