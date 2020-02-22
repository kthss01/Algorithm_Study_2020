using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace C____Study
{
    class Study
    {
        public void Output()
        {
            // format 출력
            int a = 10;

            Console.WriteLine("a = {0}", a);

            // 숫자형식 포맷팅을 이용하면 숫자로 이루어진 문자열을 다양한 형태로 출력 가능
            Console.WriteLine("{0:C}", 2.5); // 통화 ₩3 
            Console.WriteLine("{0:C}", -3.5); // 통화 -₩4
            Console.WriteLine("{0:D}", 00035); // 10진법 35
            Console.WriteLine("{0:E}", 342); // 과학적지수 3.420000E+02
            Console.WriteLine("{0:F2}", 35.22); // 고정 소수점 35.22
            Console.WriteLine("{0:F0}", 35.22); // 고정 소수점 35
            Console.WriteLine("{0:G}", 123456); // 일반 123456
            Console.WriteLine("{0:N}", 25000000); // 숫자 25,000,000.00
            Console.WriteLine("{0:N}", 25000000); // 숫자 25,000,000.00
            Console.WriteLine("{0:P}", .21548); // 백분율 21.55%
            Console.WriteLine("{0:P1}", .112345); // 백분율 11.2%
            Console.WriteLine("{0:X}", 250); // 16진법 FA
            Console.WriteLine("{0:X}", 0xffff); // 16진법 FFFF


            // Format() 메소드
            int num = 999;
            string str1 = string.Format("Example2 : {0}, {1}, {2}", "BlockDMask", 3434, num);

            // 소수점 자리수 
            /*
             * .ToString("F") 2자리
             * .ToString("F0") 0자리
             * .ToString("F1") 1자리
             * 
             * N은 3자리마다 콤마가 표시됨
             * d.ToString("N") // 1,054.32
             * d.ToString("N0") // 1,054
             * d.ToString("N1") // 1,054.3
             * d.ToString("N2") // 1,054.32
             */
            double d = 1054.32179;

            Console.WriteLine(d.ToString("F"));
            Console.WriteLine(d.ToString("F0"));
            Console.WriteLine(d.ToString("F1"));
            Console.WriteLine(d.ToString("F2"));
            Console.WriteLine(d.ToString("F3"));

            Console.WriteLine(d.ToString("N"));
            Console.WriteLine(d.ToString("N0"));
            Console.WriteLine(d.ToString("N1"));
            Console.WriteLine(d.ToString("N2"));
            Console.WriteLine(d.ToString("N3"));
        }

        public void StringBuilder()
        {
            // C# StringBuilder 클래스
            /*
             * 문자열을 다루는데 중요한 클래스 중의 하나
             * String 클래스는 Immutable이기 때문에, 문자열 갱신을 많이하는 프로그램에는
             * Mutable 타입인 StringBuilder 클래스 사용해야함
             * 이 클래스는 생성, 소멸하지 않고 일정한 버퍼를 갖고
             * 문자열 갱신을 효율적으로 처리
             * 특히 루프 안에서 계속 문자열을 추가 변경하는 코드에서는
             * string 대신 StringBuilder를 사용해야함
             */

            StringBuilder sb = new StringBuilder();
            for(int i=1; i<=26; i++)
            {
                sb.Append(i.ToString());
                sb.Append(System.Environment.NewLine);
            }
            string s = sb.ToString();
            Console.WriteLine(s);
        }

        public void Input()
        {
            // 입력 받기
            /*
             * Console.ReadLine() // string으로 입력받음
             */

            // 자료형 변환
            /*
             * string으로 입력받으므로 .Parse() 나 Convert.To~~~() 이용
             */

            int input;
            Console.Write("숫자를 입력하세요: ");

            //input = int.Parse(Console.ReadLine());

            string strInput;
            strInput = Console.ReadLine();
            input = Convert.ToInt32(strInput);

            Console.WriteLine("입력한 숫자는 " + input);
        }

        public void MultiInput()
        {
            // 여러 수 입력받기
            /*
             * string으로 받아서 split으로 잘라서 씀
             */

            int n;
            n = int.Parse(Console.ReadLine());

            //int[] arr = new int[n];
            //string str;
            //string[] token;
            //str = Console.ReadLine();
            //{
            //    token = str.Split(' ');
            //    for(int i = 0; i < token.Length; i++)
            //    {
            //        token[i].Trim();
            //        arr[i] = Convert.ToInt32(token[i]);
            //    }
            //}

            // 더 쉬운 방법
            int[] arr = Array.ConvertAll(
                Console.ReadLine().Split(' '), arrTemp => Convert.ToInt32(arrTemp));

            for (int i = 0; i < n; i++) 
                Console.Write("[{0}] ", arr[i]);
            Console.WriteLine();
        } 

        public void Foreach()
        {
            // foreach 활용
            int[] arr = new int[] { 11, 12, 13, 14, 15, 16, 17 };

            int index = 0;
            foreach(int elem in arr)
            {
                Console.WriteLine("arr[{0}] = {1}", index, elem);
                index++;
            }
        }

        #region enum 예제
        public enum Category
        {
            Cake,
            IceCream,
            Bread
        }
        enum City
        {
            Seoul, // 0
            Daejun, // 1
            Busan = 5, // 5
            Jeju = 10 // 10
        }
        [Flags]
        enum Border
        {
            None = 0,
            Top = 1,
            Right = 2,
            Bottom = 4,
            Left = 8
        }
        #endregion

        public void Enum()
        {
            // C# enum (열거형)
            /*
             * 별도의 지정없이는 처음이 0,1,2,...
             * enum문은 클래스 안이나 네임스페이스 내에서만 선언될 수 있음
             * 즉, 메서드 안이나 속성 안에서는 선언되지 않음
             */

            /*
             * enum 타입은 숫자형 타입과 호환가능
             */

            City myCity;
            myCity = City.Seoul;

            int cityValue = (int)myCity;

            if (myCity == City.Seoul)
                Console.WriteLine("Welcome to Seoul");

            // 플래그(flag) enum
            /*
             * enum의 각 멤버들은 각 비트별로 구분되는 값들(ex:1,2,4,8,...)을 갖을 수 있는데
             * 이렇게 enum 타입이 비트 필드를 갖는다는 것을 표시하기 위해
             * enum 선언문 바로 위에 [Flags] 라는 Attribute를 지정할 수 있음
             * 
             * [Flags] 특성을 갖는 플래그 enum은 OR 연산자를 이용해서 한 enum 변수에 다중값을
             * 가질 수 있으며 AND 연산자를 이용하여 enum 변수가 특정 멤버를 포함하고 있는지
             * 체크할 수 있다.
             */

            // OR 연산자로 다중 플래그 할당
            Border b = Border.Top | Border.Bottom;

            // & 연산자로 플래그 체크
            if ((b & Border.Top) != 0)
            {
                // HasFlag() 이용 플래그 체크
                if(b.HasFlag(Border.Bottom))
                {
                    // "Top, Bottom" 출력
                    Console.WriteLine(b.ToString());
                }
            }
        }

        public void Operator()
        {
            // ?? 연산자
            /*
             * Null-coalescing operator라고 불리우는 특별한 연산자로
             * C# 3.0이상에서 지원하는 연산자
             * 
             * ?? 연산자는 ?? 왼쪽 피연산자의 값이 NULL인 경우 ?? 뒤의 피연산자 값을 리턴하고,
             * 아니면 그냥 ?? 앞의 피연산자 값을 리턴한다.
             * ?? 연산자는 왼쪽 피연산자가 NULL이 허용되는 데이터 타입인 경우에만 사용
             * ex)
             * int 타입은 NULL을 가질 수 없으므로 허용되지 않지만,
             * Nullable<int> 즉 int? 타입은 허용
             */

            int? i = null;
            i = i ?? 0;

            string s = null;
            s = s ?? string.Empty;
        }
    }

    // C# Yield
    class YieldPractice
    {
        /*
         * C#의 yield 키워드는 호출자(Caller)에게 컬렉션 데이타를 하나씩 리턴할 때 사용한다. 
         * 흔히 Enumerator(Iterator)라고 불리우는 이러한 기능은 집합적인 데이타셋으로부터 
         * 데이타를 하나씩 호출자에게 보내주는 역할을 한다.
         * yield는 yield return 또는 yield break의 2가지 방식으로 사용되는데, 
         * (1) yield return은 컬렉션 데이타를 하나씩 리턴하는데 사용되고, 
         * (2) yield break는 리턴을 중지하고 Iteration 루프를 빠져 나올 때 사용한다.
         */

        /*
         * (1) 만약 데이타의 양이 커서 모든 데이타를 한꺼번에 리턴하는 것하는 것 보다 
         * 조금씩 리턴하는 것이 더 효율적일 경우. 
         * 예를 들어, 어떤 검색에서 1만 개의 자료가 존재하는데, 
         * UI에서 10개씩만 On Demand로 표시해 주는게 좋을 수도 있다. 
         * 즉, 사용자가 20개를 원할 지, 1000개를 원할 지 모르기 때문에, 
         * 일종의 지연 실행(Lazy Operation)을 수행하는 것이 나을 수 있다.
         * (2) 어떤 메서드가 무제한의 데이타를 리턴할 경우. 
         * 예를 들어, 랜덤 숫자를 무제한 계속 리턴하는 함수는 
         * 결국 전체 리스트를 리턴할 수 없기 때문에 yield 를 사용해서 구현하게 된다.
         * (3) 모든 데이타를 미리 계산하면 속도가 느려서 
         * 그때 그때 On Demand로 처리하는 것이 좋은 경우. 
         * 예를 들어 소수(Prime Number)를 계속 리턴하는 함수의 경우, 
         * 소수 전체를 구하면 (물론 무제한의 데이타를 리턴하는 경우이기도 하지만) 
         * 시간상 많은 계산 시간이 소요되므로 다음 소수만 리턴하는 함수를 만들어 
         * 소요 시간을 분산하는 지연 계산(Lazy Calculation)을 구현할 수 있다.
         */

        IEnumerable<int> GetNumber()
        {
            yield return 10; // 첫번째 루프에서 리턴되는 값
            yield return 20; // 두번째 루프에서 리턴되는 값
            yield return 30; // 세번째 루프에서 리턴되는 값
        }

        public void Print()
        {
            foreach (int num in GetNumber())
            {
                Console.WriteLine(num);
            }
        }

        /*
         * 인터페이스 공부시 한번더 보자 우선은 예제만 간단히 정리
         */

        public class MyList
        {
            private int[] data = { 1, 2, 3, 4, 5 };

            public IEnumerator GetEnumerator()
            {
                int i = 0;
                while(i < data.Length)
                {
                    yield return data[i];
                    i++;
                }
            }
        }

        public void Enumerator()
        {
            var list = new MyList();

            // foreach 사용하여 Iteration
            foreach (var item in list)
            {
                Console.WriteLine(item);
            }

            // 수동 Iteration
            IEnumerator it = list.GetEnumerator();
            it.MoveNext();
            Console.WriteLine(it.Current); // 1
            it.MoveNext();
            Console.WriteLine(it.Current); // 2
        }
    }

    // C# delegate
    // 좀더 공부 다시 정리
    class DelegatePractice
    {
        /*
         * C# delegate는 C/C++의 함수 포인터와 비슷한 개념으로 매서드 파라미터와 리턴 타입에 대한
         * 정의를 한 후, 동일한 파라미터와 리턴 타입을 가진 메서드를 서로 호환해서 
         * 불러 쓸 수 있는 기능이다.
         */

        // 1. delegate 선언
        private delegate void RunDelegate(int i);

        private void RunThis(int val)
        {
            // 콘솔출력 : 1024
            Console.WriteLine("{0}", val);
        }

        private void RunThat(int value)
        {
            // 콘솔출력 : 0x400
            Console.WriteLine("0x{0:X}", value);
        }

        public void Perform()
        {
            // 2. delegate 인스턴스 생성
            RunDelegate run = new RunDelegate(RunThis);
            // 3. delegate 실행
            run(1024);

            // run = new RunDelegate(RunThat); 을 줄여서
            // 아래와 같이 쓸 수 있다.
            run = RunThat;

            run(1024);
        }
    }

    /*
     * 공부해야할 거
     * 인터페이스 linq delegate 무명메서드 등
     * http://www.csharpstudy.com/CSharp/CSharp-delegate.aspx 참고해서 추후 하자
     */

    class Program
    {
        static void Main(string[] args)
        {
            Study study = new Study();
            //study.Output();  // 출력 예제
            //study.Input(); // 입력받기 예제
            //study.MultiInput(); // 여러 수 입력받기 예제
            //study.Foreach(); // foreach 예제
            //study.StringBuilder(); // StringBuliider 예제
            //study.Enum(); // enum 예제

            YieldPractice yPractice = new YieldPractice();
            yPractice.Print();

            //DelegatePractice dPractice = new DelegatePractice();
            //dPractice.Perform();
        }
    }
}
