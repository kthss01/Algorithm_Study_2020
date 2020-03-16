// The Time in Words
/*
 * 시간 부르는 규칙에 맞게 출력하기
 * 
 * minutes = 0, use o' clock
 * 1 <= minutes <= 30 use past
 * 30 < minutes use to
 * 
 * ex)
 * 5:00 -> five o' clock
 * 5:01 -> one minute past five
 * 5:10 -> ten minutes past five
 * 5:15 -> quarter past five
 * 5:30 -> half past five
 * 5:40 -> twenty minutes to six
 * 5:45 -> quarter to six
 * 5:47 -> thirteen minutes to six
 * 5:28 -> twenty eight minutes past five
 * 
 * 1 <= h <= 12
 * 0 <= m < 60
 */

using System;

namespace The_Time_in_Words
{
    class Program
    {
        static string timeInWords(int h, int m)
        {
            string[] words = new string[]
            {
                "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                "ten", "eleven", "twelve", "thirteen", "fourteen", "quarter",
                "sixteen", "seventeen", "eighteen", "nineteen", "twenty",
                "twenty one", "twenty two", "twenty three", "twenty four",
                "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine",
                "half"
            };

            string time = "";

            if (m == 0)
                time = words[h] + " " + "o' clock";
            else if (m == 1)
                time = words[m] + " minute past " + words[h];
            else if (m == 15)
                time = words[m] + " past " + words[h];
            else if (m > 1 && m < 30)
                time = words[m] + " minutes past " + words[h];
            else if (m == 30)
                time = words[m] + " past " + words[h];
            else if (m == 45)
                time = words[m - 30] + " to " + words[h + 1];
            else if (m > 30 && m < 60)
                time = words[60 - m] + " minutes to " + words[h + 1];

            return time;
        }

        static void Main(string[] args)
        {
            int h = Convert.ToInt32(Console.ReadLine());
            int m = Convert.ToInt32(Console.ReadLine());

            string result = timeInWords(h, m);
            Console.WriteLine(result);
        }
    }
}
