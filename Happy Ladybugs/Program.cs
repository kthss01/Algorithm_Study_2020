// Happy Ladybugs
/*
 * ladybug 무당벌레
 * 
 * 규칙
 * 무당벌레는 같은 색의 무당벌레와 붙어있으면 행복해짐
 * 대문자로 구분하고 빈 곳은 _로 표시
 * 빈 곳으로 무당벌레를 옮길 수 있음
 * 모든 무당벌레가 행복할 수 있는지 체크하기
 * 
 * ex)
 * b = [YYR_B_BR] -> [YYRRBB__] 가 되어서 행복할 수 있음
 * 1 <= g, n <= 100 g 게임 수, n 보드의 공간 수
 * b[i] _, A ~ Z
 */

using System;

namespace Happy_Ladybugs
{
    class Program
    {
        static string happyLadybugs(string b)
        {
            bool result = true;

            if (b.Contains("_"))
            {
                int[] alphabets = new int[27];

                for(int i=0; i<b.Length; i++)
                {
                    if (b[i] == '_')
                        alphabets[26]++;
                    else
                        alphabets[b[i] - 'A']++;
                }

                for (int i = 0; i < 26; i++)
                {
                    if (alphabets[i] == 1)
                    {
                        result = false;
                        break;
                    }
                
                }
            }
            else
            {
                int cnt = 0;
                char temp = '_';

                for (int i=0; i<b.Length; i++)
                {
                    if (i == 0 && b[i] != '_')
                    {
                        cnt = 1;
                        temp = b[i];
                    }
                    else if (b[i] == temp)
                    {
                        cnt++;
                    }
                    else
                    {
                        if (cnt == 1)
                        {
                            result = false;
                            break;
                        }
                        else
                        {
                            cnt = 1;
                            temp = b[i];
                        }
                    }
                }

                if (cnt == 1)
                    result = false;
            }

            return result ? "YES" : "NO";
        }

        static void Main(string[] args)
        {
            int g = Convert.ToInt32(Console.ReadLine());

            for (int gItr = 0; gItr < g; gItr++)
            {
                int n = Convert.ToInt32(Console.ReadLine());
                string b = Console.ReadLine();

                string result = happyLadybugs(b);
                Console.WriteLine(result);
            }
        }
    }
}
