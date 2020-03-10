// Taum and B'day
/*
 * b와 w를 살 때 가장 적은 가격으로 살 수 있는 방법 구하기
 * 
 * ex)
 * b = 3 w = 5
 * bc = 3, wc = 4 (각 가격), z = 1(전환시 비용) - b w 서로 바꿀 때 비용이 듬
 * 
 * 3 x 3 + 5 x 4 = 29 (b 4개 사고 c 4개 산후 비용 1 추가)
 * 
 * 1 <= t <= 10
 * 0 <= b,w,bc,wc,z <= 10^9
 */

using System;

namespace Taum_and_B_day
{
    class Program
    {
        public static long taumBday(int b, int w, int bc, int wc, int z)
        {
            if (bc + z < wc)
            {
                return (long)b * (long)bc + (long)w * (long)(bc + z);
            }
            else if (wc + z < bc)
            {
                return (long)w * (long)wc + (long)b * (long)(wc + z);
            }
            else
            {
                return (long)b * (long)bc + (long)w * (long)wc;
            }
        }

        static void Main(string[] args)
        {
            int t = Convert.ToInt32(Console.ReadLine().Trim());

            for (int tItr = 0; tItr < t; tItr++) 
            {
                string[] firstMultipleInput = Console.ReadLine().TrimEnd().Split(' ');
                int b = Convert.ToInt32(firstMultipleInput[0]);
                int w = Convert.ToInt32(firstMultipleInput[1]);
                
                string[] secondMultipleInput = Console.ReadLine().TrimEnd().Split(' ');
                int bc = Convert.ToInt32(secondMultipleInput[0]);
                int wc = Convert.ToInt32(secondMultipleInput[1]);
                int z = Convert.ToInt32(secondMultipleInput[2]);

                long result = taumBday(b, w, bc, wc, z);
                Console.WriteLine(result);
            }
        }
    }
}
