// Append and Delete
/*
 * 한 문자열을 다른 문자열로 추가하고 지우는 방법으로 바꾸는게 가능한지 알아보기
 * 횟수 k에 할 수 있으면 YES 아니면 NO 출력
 * 
 * 추가하고 지우는건 마지막 문자만 가능
 * 
 * 1 <= |s| <= 100 초기 문자열
 * 1 <= |t| <= 100 바꿀 문자열
 * 1 <= k <= 100 횟수
 * s,t 소문자로 이루어짐
 */

using System;

namespace Append_and_Delete
{
    class Program
    {
        static string appendAndDelete(string s, string t, int k)
        {
            int minLen = Math.Min(s.Length, t.Length);
            int sameLen = 0;
            for(int i=0; i<minLen; i++)
            {
                if (s[i] == t[i])
                    sameLen++;
                else
                    break;
            }

            if (s.Length + t.Length <= k)
                return "Yes";
            if(s.Length + t.Length - sameLen * 2 == k)
                return "Yes";
            if(s.Length + t.Length - sameLen * 2 < k)
            {
                int temp = k - (s.Length + t.Length - sameLen * 2);
                if (temp % 2 == 0)
                    return "Yes";
            }

            return "No";
        }

        static void Main(string[] args)
        {
            string s = Console.ReadLine();
            string t = Console.ReadLine();
            int k = Convert.ToInt32(Console.ReadLine());

            string result = appendAndDelete(s, t, k);
            Console.WriteLine(result);
        }
    }
}
