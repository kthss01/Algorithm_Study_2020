// Plus Minus
/*
 * array 받았을 때 양수 0 음수 비율이 어떻게 되는지 소수점으로 출력
 * 오차는 10^-4까지
 * 
 * 0 < n <= 100
 * -100 <= arr[i] <= 100
 * 
 */

using System;

namespace Plus_Minus
{
    class Program
    {
        static void Main(string[] args)
        {
            int n;
            n = int.Parse(Console.ReadLine());

            int[] arr = new int[n];

            string str;
            string[] token;
            str = Console.ReadLine();
            {
                token = str.Split(' ');
                for(int i=0; i<token.Length; i++)
                {
                    token[i].Trim();
                    arr[i] = Int32.Parse(token[i]);
                }
            }

            int pos = 0, zero = 0, neg = 0;
            for(int i=0; i<n; i++)
            {
                if (arr[i] > 0) pos++;
                else if (arr[i] < 0) neg++;
                else zero++;
            }

            Console.WriteLine(((double)pos / (double)n).ToString("F6"));
            Console.WriteLine(((double)neg / (double)n).ToString("F6"));
            Console.WriteLine(((double)zero / (double)n).ToString("F6"));

        }
    }
}
