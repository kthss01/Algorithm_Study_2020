// Minimum Distances
/*
 * 배열이 있는데 여기서 거리를
 * 같은 숫자가 나올 때에 인덱스 번호 차로 정의한다고 할 때
 * 최소 거리 구하기 없으면 -1 
 * 
 * ex)
 * [3,2,1,2,3]
 * 3 (i=0, j=4) - 4
 * 2 (i=1, j=3) - 2
 * => 2
 * 
 * 1 <= n <= 10^3
 * 1 <= a[i] <= 10^5
 */

using System;

namespace Minimum_Distances
{
    class Program
    {
        static int minimumDistances(int[] a)
        {
            int minD = -1;

            bool bFind = false;
            for(int i=0; i < a.Length; i++)
            {
                for(int j=a.Length-1; j >= 0; j--)
                {
                    if (i == j || a[i] != a[j]) continue;
                    else
                    {
                        if (!bFind)
                        {
                            bFind = true;
                            minD = Math.Abs(i - j);
                        }
                        else
                            minD = Math.Min(Math.Abs(i - j), minD);
                    }
                }
            }

            return minD;
        }

        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());
            int[] a = Array.ConvertAll(Console.ReadLine().Split(' '),
                aTemp => Convert.ToInt32(aTemp));

            int result = minimumDistances(a);
            Console.WriteLine(result);
        }
    }
}
