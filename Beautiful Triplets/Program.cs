// Beautiful Triplets
/*
 * triplets 세 쌍둥이
 * 연속 된 수가 주어질 때 
 * 
 * a[i], a[j], a[k]
 * i < j < k
 * a[j] - a[i] = a[k] - a[j] = d 인 수를 구하기
 * 
 * 1 <= n <= 10^4
 * 1 <= d <= 20
 * 0 <= arr[i] <= 2 x 10^4
 * arr[i] > arr[i-1]
 */

using System;

namespace Beautiful_Triplets
{
    class Program
    {
        static int beautifulTriplets(int d, int[] arr)
        {
            int len = arr.Length;
            int cnt = 0;

            for(int i=0; i < len-2; i++)
            {
                for(int j=i+1; j < len-1; j++)
                {
                    int temp = arr[j] - arr[i];
                    if (temp != d) continue;

                    for(int k=j+1; k < len; k++)
                    {
                        temp = arr[k] - arr[j];
                        if (temp != d) continue;
                        cnt++;
                    }
                }
            }

            return cnt;
        }

        static void Main(string[] args)
        {
            string[] nd = Console.ReadLine().Split(' ');
            int n = Convert.ToInt32(nd[0]);
            int d = Convert.ToInt32(nd[1]);

            int[] arr = Array.ConvertAll(Console.ReadLine().Split(' '),
                arrTemp => Convert.ToInt32(arrTemp));

            int result = beautifulTriplets(d, arr);
            Console.WriteLine(result);
        }
    }
}
