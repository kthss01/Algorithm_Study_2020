using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Linq;

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

    class Practice
    {
        public virtual void Example() { }
    }

    // C# Yield
    class Yield : Practice
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

        public override void Example()
        {
            foreach (int num in GetNumber())
            {
                Console.WriteLine(num);
            }

            Enumerator();
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
    delegate int MyDelegate(int a, int b);
    delegate void MyDelegate2();
    delegate void MyDelegate3(int a);
    delegate void MyDelegate4(int a, int b);
    class Delegate : Practice
    {
        /*
         * 메소드를 참조하는 변수 (메소드를 대신해서 호출)
         */
        public override void Example()
        {
            Basic();
            CallBackMethod();
            DelegateChain();
            Event();
        }

        public static void Calculator(int a, int b, MyDelegate dele)
        {
            Console.WriteLine(dele(a, b));
        }
        public static int Plus(int a, int b) { return a + b; }
        public static int Minus(int a, int b) { return a - b; }
        public static int Multiply(int a, int b) { return a * b; }

        void Basic()
        {
            MyDelegate calculate;

            calculate = new MyDelegate(Plus);
            int sum = calculate(11, 22);
            Console.WriteLine("11 + 22 = {0}", sum);

            calculate = new MyDelegate(Minus);
            Console.WriteLine("22 - 11 = {0}", calculate(22, 11));
        }

        // 콜백메서드
        /*
         * 델리게이트는 콜백메서드를 구현할 때 나타남
         * 콜백(Callback)이란 A라는 메서드를 호출할 때에 B라는 메서드를 넘겨주어
         * A 메서드로 하여금 B 메서드를 호출하도록 하는 것을 말하며
         * 이때의 A 메서드를 콜백메서드라 한다.
         * 
         * 이 과정에서 델리게이트는 B메서드를 참조하는 변수로써 A메서드에게 넘겨지는
         * 매개변수가 되고, A메서드는 매개변수로 받은 델리게이트로 B메서드를 호출한다.
         */
        void CallBackMethod()
        {
            MyDelegate plus = new MyDelegate(Plus);
            MyDelegate minus = new MyDelegate(Minus);
            MyDelegate multiply = new MyDelegate(Multiply);

            Calculator(11, 22, plus);
            Calculator(33, 22, minus);
            Calculator(11, 22, multiply);
        }

        public static void func0() { Console.Write("1번째 "); }
        public static void func1() { Console.Write("2번째 "); }
        public static void func2() { Console.Write("3번째 "); }

        // 델리게이트 체인
        /*
         * 델리게이트는 여러개의 메소드를 참조할 수 있음
         * +, +=로 새로운 메소드를 추가만 해주면 됨
         * 
         * MyDelegate del;
         * 
         * del = new MyDelegate(func0);
         * del += func1;
         * del += func2;
         * 
         * 이제 델리게이트를 호출하면, 참조된 메소드들을 차례대로 호출하게 됨
         * 이렇게 하나의 델리게이트에 여러개의 메소드를 연결시키는 것을 델리게이트 체인이라 한다.
         * 그리고 델리게이트에 연결된 메소드를 끊기 원한다면 반대로 -= 해주면 됨
         */
         void DelegateChain()
        {
            MyDelegate2 dele;
            dele = new MyDelegate2(func0);
            dele += func1;
            dele += func2;

            dele();
            Console.WriteLine();

            dele -= func0;
            dele -= func2;

            dele();
            Console.WriteLine();
        }

        /*
         * 이벤트
         * 델리게이트 타입을 선언하면 델리게이트 변수도 생성할 수 있지만,
         * 이벤트 변수도 생성할 수 있다. 이벤트 변수는 간단히 event 한정자만 붙여줌녀 된다.
         * 
         * event MyDelegate B;
         * 
         * 이벤트 변수는 델리게이트 변수와 마찬가지로 메소드를 참조하는데,
         * 간단히 말해 델리게이트 변수가 public이라면 이벤트 변수는 private 같은 느낌이랄까
         * 델리게이트 변수는 자신이 속한 클래스 외부에서도 호출이 가능하지만,
         * 이벤트 변수는 외부에서 호출이 불가능하다.
         */
        class EventManager
        {
            public event MyDelegate3 eventCall;
            public void NumberCheck(int num)
            {
                if (num % 2 == 0)
                    eventCall(num);
            }
        }
        static void EvenNumber(int num)
        {
            Console.WriteLine("{0}는 짝수", num);
        }
        void Event()
        {
            EventManager eventManager = new EventManager();
            eventManager.eventCall += new MyDelegate3(EvenNumber);

            for (int i = 1; i < 10; i++)
                eventManager.NumberCheck(i);
        }
    }

    // C# Collection
    class Collection : Practice
    {
        /*
         * 컬렉션(Collection)은 데이터 모음(자료구조)
         */

        public override void Example()
        {
            /*
             *  Collection은 어떤 타입의 데이터든지 담을 수 있는 대신
             *  object 형식으로 박싱(Boxing) 언박싱(Unboxing)하기 때문에 성능 문제가 있음
             *  따라서 일반화 컬렉션을 사용함
             *  
             *  List<T>
             *  Stack<T>
             *  Queue<T>
             *  Dictionary<T>
             */

            // ArrayList
            ArrayList list = new ArrayList();

            list.Add(10); list.Add(20); list.Add(30); // 10,20,30
            list.RemoveAt(1); // list.Remove(20)과 같은 결과

            list.Insert(1, 2.3f); // 10, 2.3, 30
            list.Add("ABC"); // 10, 2.3, 30, ABC
            list.Add("가나다"); // 10, 2.3, 30, ABC, 가나다

            // 컬렉션의 모든 요소는 object 타입으로 저장됨
            foreach (object obj in list)
                Console.WriteLine("{0}", obj);
            Console.WriteLine();

            // Queue
            Queue que = new Queue();
            que.Enqueue(10);
            que.Enqueue(20);
            que.Enqueue(30);
            que.Dequeue();
            que.Enqueue(4.4);
            que.Dequeue();
            que.Enqueue("ABC");

            while (que.Count > 0)
                Console.WriteLine(que.Dequeue());
            Console.WriteLine();

            // Stack
            Stack stack = new Stack();

            stack.Push(10);
            stack.Push(20);
            stack.Push(30);
            stack.Pop();
            stack.Pop();
            stack.Push(4.4);
            stack.Push("ABC");

            while (stack.Count > 0)
                Console.WriteLine(stack.Pop());
            Console.WriteLine();

            // Hashtable
            // Key Value을 가진 데이터를 저장하는 자료구조
            Hashtable ht = new Hashtable();
            ht["Apple"] = "사과";
            ht["Banana"] = "바나나";
            ht["Orange"] = "오렌지";

            Console.WriteLine(ht["Apple"]);
            Console.WriteLine(ht["Banana"]);
            Console.WriteLine(ht["Orange"]);
        }
    }

    // Anonymous
    class Anonymous : Practice
    {

        public override void Example()
        {
            AnonymousType();
            AnonymousMethod();
        }
        
        /*
         * 무명 형식 (Anonymous Type)
         * C#에는 이름이 없는 형식(타입)이 존재
         * 무명형식이라고 하며 임시 변수가 필요할 때 아주 유용
         * 
         * var temp = new {Age = 11, Name = "십일"};
         * Console.WriteLine("{0},{1}", temp.Age, temp.Name};
         * 
         * 무명형식은 반드시 선언과 함께 new 키워드로 인스턴스를 생성해주어야 하며,
         * 생성된 인스턴스는 읽기전용이기 때문에 값 변경이 불가능하다.
         * 
         */
        void AnonymousType()
        {
            var temp = new { Age = 11, Name = "십일" };
            Console.WriteLine("Age:{0}, Name:{1}", temp.Age, temp.Name);

            var tempArr = new
            {
                Int = new int[] { 11, 22, 33, 44, 55 },
                Float = new float[] { 0.1f, 0.2f, 0.3f }
            };

            foreach (var element in tempArr.Int)
                Console.Write("{0} ", element);
            Console.WriteLine();

            foreach (var element in tempArr.Float)
                Console.Write("{0} ", element);
            Console.WriteLine();
        }

        /*
         * 무명 메소드 (Anonymous Method)
         * 
         * C# 이름이 없는 무명 메소드 제공
         * (델리게이트와 함께 사용됨)
         * 
         * 무명 메소드는 이름이 없기 때문에 메소드를 호출하기 위해 델리게이트 변수 필요
         * 즉, 델리게이트 변수를 선언하고, 그 변수로 무명 메소드를 참조하게됨
         * (델리게이트와 무명메소드는 당연히 같은 형식이어야 한다.)
         */
        void AnonymousMethod()
        {
            // 델리게이트 변수 선언
            MyDelegate add;

            // 무명 메소드 참조
            add = delegate (int a, int b)
            {
                return a + b;
            };

            Console.WriteLine(add(11, 22));
        }
    }

    // Lamda Expression
    class LamdaExpression : Practice
    {
        /*
         * 무명 메소드를 단순한 계산식으로 표현한 것
         * 메소드는 크게 매개변수와 내부 식, 반환값으로 구성되어 있는데,
         * 이들만 가지고 메소드를 계산식으로 표현
         * 
         * MyDelegate A
         *
         * 무명 메소드
         * A = delegate(int a, int b) {return a + b;};
         * 
         * 람다식
         * A = (int a, int b) => a+b;
         * 동일한 람다식
         * A = (a,b) => a+b;
         * 람다식은 매개변수로 전해지는 a,b의 타입까지도 생략이 가능하다.
         */

        public override void Example()
        {
            Basic();
            Expression();
        }

        public void Basic()
        {
            MyDelegate add = (a, b) => a + b;
            MyDelegate2 lamda = () => Console.WriteLine("람다식");

            Console.WriteLine("11 + 22 = {0}", add(11, 22));

            lamda();
        }

        /*
         * 문 형식의 람다식
         * 람다식 내에서 메소드처럼 다양한 처리도 가능하다
         * 그냥 메소드처럼 중괄호 내에 작성하면 된다
         * 
         * delegate void MyDelegate(int a, int b);
         * 
         * MyDelegate A = (a, b) =>
         * {
         *     if(a > b)
         *          Console.WriteLine("{0}가 크다", a);
         *     else if(a < b)
         *          Console.WriteLine("{0}가 크다", b);
         *     else
         *          Console.WriteLine("{0}, {1}는 같다", a,b);
         * };
         */
         public void Expression()
        {
            MyDelegate4 Compare = (a, b) =>
            {
                if (a > b)
                    Console.WriteLine("{0}보다 {1}가 크다", b, a);
                else if (a < b)
                    Console.WriteLine("{0}보다 {1}가 크다", a, b);
                else
                    Console.WriteLine("{0}, {1}는 같다", a, b);
            };

            Compare(11, 22);
        }
    }

    // Func & Action 델리게이트
    class FuncAction : Practice
    {
        /*
         * 무명 메소르를 사용하기 위해서는 이를 참조할 수 있는 델리게이트 변수가 있어야 하며,
         * 또한 델리게이트 변수를 생성하기에 앞서 델리게이트 타입을 선언해야 한다.
         * 그러면 각기 다른 타입의 무명 메소드를 여러개 만들때는 어떻게 해야할까?
         * 당연히 무명 메소드마다 그 타입에 맞는 델리게이트 타입과 변수를 따로 따로 선언해야 할 것이다.
         * 이는 매우 비효율적인 작업이기 때문에 C#에서는 Func와 Action이라는 델리게이트를 제공한다.
         * 
         * Func와 Action은 미리 선언된 델리게이트 변수로써 별도의 선언없이 사용 가능하다.
         * Func는 반환값이 있는 메소드를 참조하는 델리게이트 변수이고
         * Action은 반환값이 없는 메소드를 참조하는 델리게이트 변수이다.
         */

        public override void Example()
        {
            Func();
            Action();
        }

        static float temp(int a, int b, int c) { return (a + b + c) * 0.1f; }
        void Func()
        {
            // 매개변수는 없고, 반환값은 float형
            Func<float> func0 = () => 0.1f; // 0.1를 반환
            // int형 매개변수를 1개 가지고 반환값은 float형
            Func<int,float> func1 = (a) => a * 0.1f;
            // int형 매개변수를 2개 가지고 반환값은 float형
            Func<int, int, float> func2 = (a, b) => (a + b) * 0.1f;
            // int형 매개변수를 3개 가지고 반환값은 float형
            Func<int, int, int, float> func3;

            func3 = new Func<int, int, int, float>(temp); // 일반 메서드 참조

            Console.WriteLine("func0 반환값: {0}", func0());
            Console.WriteLine("func1 반환값: {0}", func1(10));
            Console.WriteLine("func2 반환값: {0}", func2(10,10));
            Console.WriteLine("func3 반환값: {0}", func3(10,10,10));
        }

        static void temp2 (string name) { Console.WriteLine("name: {0}", name); }
        void Action()
        {
            int sum = 0;

            Action act0 = () => Console.WriteLine("name: 엑트0");
            Action<string> act1 = new Action<string>(temp2);
            Action<string, string> act2 = (name, age) =>
             {
                 Console.Write("name: {0}", name);
                 Console.Write("age: {0}", age);
             };
            Action<int, int, int> act3 = (a, b, c) => sum = a + b + c;

            act0();
            act1("엑트1");
            act2("엑트2", "22");
            act3(100, 20, 3);

            Console.WriteLine("sum: {0}", sum);
        }
    }

    // LINQ
    class Linq : Practice
    {
        /*
         * LINQ(링크) Languate Integrated Query의 약어로,
         * 직역하면 '질의로 통합된 언어' 이다.
         * '데이터에 대해 질문하는 언어'라고 볼 수 있따.
         * LINQ의 역할은 데이터에 대해 질문하고, 그 답에 해당하는 데이터를 찾는 것이다.
         * 이러한 LINQ의 질의 기능은 프로그램에서 데이터 검색을 편리하게 해준다.
         * 
         * 예를 들어 결혼정보업체에서 한국의 모든 사람에 대한 데이터를 가지고 있는데,
         * 그 중에 여자이면서 20세 이상 성인들의 데이터를 어린 나이순으로 찾는다고 치자.
         * 그럼 데이터를 하나하나 검색하면서 이런 질문을 던질 수 있을 것이다.
         * 
         *  첫번째. 여자인가?
         *  두번째. (검색된 여자 중에서) 20세가 넘는 성인인가?
         *  세번째. (검색된 성인 여자 중에서) 나이가 어린가?
         *  
         *  위의 질문들을 LINQ 쿼리식으로 작성하면 다음과 같다.
         *  var woman =
         *      from woman in womanList // womanList에서 (여자인가?)
         *      where woman.age > 20 // 20세가 넘는 성인을 (성인인가?)
         *      orderby woman.age // 나이 순으로 정렬하여 (나이가 어린가?)
         *      select woman; // 배열 데이터로 추출
         *      
         *  LINQ없이 단순 코드로 작성하면 다음과 같다.
         *  
         *  List<Woman> Women = new List<Woman>;
         *  
         *  foreach(Womane woman in womanList)
         *      if(woman.age > 20)
         *          Women.add(woman);
         *          
         *  Women.Sort((w1,w2) => w1.age - w2.age;);
         *  
         *  foreach(var worman in Women)
         *      Console.WriteLine("{0}, {1}", woman.name, woman.age);
         *      
         * from
         * 데이터를 검색하기 위해서는 우선적으로 데이터를 검색할 범위를 지정해 주어야한다.
         * 그 역할을 해주는 것이 from 절이다.
         * 모든 LINQ 쿼리식(Query Expression)은 반드시 from으로 시작해야 한다
         * 
         * from 절의 작성 형식은 foreach문과 거의 비슷하다.
         *  ex) foreach(var element in array) == from element in array
         *  
         *  foreach문과 from 절의 element 변수의 차이점
         *   foreach의 element 변수에는 실제로 array의 데이터가 저장된다
         *   하지만 LINQ에서는 element 변수에는 데이터가 저장되지 않고,
         *   단순히 'array에 존재하는 요소'라는 의미로만 사용된다
         *   
         *  from에서 사용가능한 타입은 IEnumerable<T> 인터페이스를 상속하는타입이다
         *  C#에서의 배열이나 컬렉션등은 모두 IEnumerable<T>를 상속하기 때문에
         *  배열이나 컬렉션 타입이라면 전부 사용가능하다.
         *  
         *  where
         *  범위 내에서 데이터를 걸러내는 역할
         *  
         *  orderby
         *  정렬해주는 연산자
         *  기본값으로 오름차순 정렬 사용
         *  ascending
         *  descending (내림차순)
         *      ex)
         *          orderby woman.age ascending
         *          orderby woman.age descending
         *          
         *  select
         *  최종적으로 검색된 데이터를 추출하는 역할
         *  추출된 데이터의 타입은 select 절에 지정한 변수의 타입으로 결정되며,
         *  무명형식(타입)으로 만들어서 추출할 수도 있다.
         *  
         *  select new {
         *      title = "성인여자", name = worman.name};
         */

        public override void Example()
        {
            Basic();
            Advance();
        }

        class Woman
        {
            public string name { get; set; }
            public int age { get; set; }
        }
        void Basic()
        {
            Woman[] womanList =
            {
                new Woman() {name = "아라", age=24},
                new Woman() {name = "민희", age=20},
                new Woman() {name = "현아", age=32},
                new Woman() {name = "수지", age=20},
            };

            var Women = from woman in womanList
                        where woman.age > 20
                        orderby woman.age ascending
                        select new
                        {
                            title = "성인 여자",
                            name = woman.name
                        };

            foreach (var woman in Women)
                Console.WriteLine("{0}: {1}", woman.title, woman.name);
        }

        void Advance()
        {
            Fromfrom();
            GroupBy();
            Join();
        }
        class Student
        {
            public string name { get; set; }
            public int[] score { get; set; }
        }
        void Fromfrom()
        {
            /*
             * 여러개의 데이터 범위 지정하기
             * 만약에 지정한 데이터 범위 내에서 한번 더 데이터 범위를 지정하려면 
             * from절을 중첩해서 사용하면 된다.
             */
            Student[] studentList =
            {
                new Student() {name = "아라", score = new int[] {88,73,66,91}},
                new Student() {name = "민희", score = new int[] {78,95,89,52}},
                new Student() {name = "현자", score = new int[] {88,71,100,91}}
            };

            var Students = from student in studentList
                           from score in student.score
                           where score > 89
                           select new { Name = student.name, Score = score };

            foreach (var student in Students)
                Console.WriteLine("참잘했어요: {0} {1}점", student.Name, student.Score);
        }
        class Person
        {
            public string sex { get; set; }
            public string name { get; set; }
        }
        void GroupBy()
        {
            // group by로 데이터 분류하기
            /*
             * 배열을 특정 기준에 따라 두 그룹으로 나누고 싶을 때
             * group ~ by ~ into 이다.
             * 
             * group A by B into C : A를 B 기준에 따라 분류하여 C로 저장한다.
             *  (C 안에는 기준에 따라 두 개의 그룹으로 나눠서 저장된다.)
             */
            Person[] peopleList =
           {
                new Person() { sex="여자", name="아라" },
                new Person() { sex="남자", name="쓰레기" },
                new Person() { sex="여자", name="민희" },
                new Person() { sex="남자", name="삼천포" }
            };

            var Group = from person in peopleList
                        group person by person.sex == "남자" into data
                        select new { bMale = data.Key, People = data };

            foreach (var group in Group)
            {
                if (group.bMale)
                {
                    Console.WriteLine("<남자 리스트>");
                    foreach (var person in group.People)
                        Console.WriteLine("이름: {0}", person.name);
                }
                else
                {
                    Console.WriteLine("<여자 리스트>");
                    foreach (var person in group.People)
                        Console.WriteLine("이름: {0}", person.name);
                }
            }
        }

        class Profile
        {
            public string name { get; set; }
            public int age { get; set; }
        }
        class Score
        {
            public string name { get; set; }
            public int math { get; set; }
            public int english { get; set; }
        }
        void Join()
        {
            /*
            * join - 두 데이터 합치기
            * 
            * 서로 다른 두 개의 데이터가 있는데, 두 개의 데이터가 서로 통합될 수 있는
            * 유사성을 가진다면 하나의 데이터로 통합하여 처리하는 것이 효율적이다.
            * LINQ는 이를 위해 데이터를 통합하는 기능을 제공하는데, 그 기능을 하는 키워드가
            * join이다.
            * join은 LINQ 쿼리식에서 서로 다른 두 데이터를 합치는 기능을 수행한다.
            * join에는 내부 조인과 외부 조인이 있다.
            */

            /*
            * (1) 내부조인
            *  내부 조인은 두 데이터를 비교해서 특정 조건이 일치하는 경우에만 추출하여 통합
            *      from a in A
            *      join b in B on a.XXX equals b.YYY
            *      // a.XXX와 b.YYY가 일치하는 a, b 데이터만 추출
            */

            Profile[] profileList =
            {
                new Profile() {name = "수지", age = 11 },
                new Profile() {name = "아라", age = 22 },
                new Profile() {name = "민희", age = 33 }
            };

            Score[] scoreList =
            {
                new Score() {name = "아라", math = 99, english = 66 },
                new Score() {name = "민희", math = 77, english = 88 },
                new Score() {name = "현아", math = 66, english = 99 },
            };

            var Students = from profile in profileList
                           join score in scoreList on profile.name equals score.name
                           select new
                           {
                               Name = profile.name,
                               Age = profile.age,
                               Math = score.math,
                               English = score.english
                           };

            foreach (var student in Students)
                Console.WriteLine(student);

            Console.WriteLine();

            /*
             * (2) 외부 조인
             * 
             * 기본적으로 내부 조인과 비슷하다.
             * 다만 조건이 일치하지 않더라도, 기준데이터를 하나도 누락시키지 않고
             * 그대로 추출한 후에, 빈 데이터를 채워서 통합한다.
             *      from a in A
             *      join b in B on a.XXX equals b.YYY into tmpe
             *      // a.XXX와 b.YYY가 일치하는 a, b 데이터 추출하여 temp에 저장
             *      // a 데이터는 하나도 누락되지 않는다
             *      from b in temp.DefaultEmpty(new a() {empty="공백"})
             *      // temp에서 비어있는 데이터를 채운 후, 다시 b 데이터로 가져온다.
             */

            var Students2 = from profile in profileList
                            join score in scoreList on
                                profile.name equals score.name into temp
                            from score in temp.DefaultIfEmpty(
                                new Score() { math = 100, english = 100 })
                            select new
                            {
                                Name = profile.name,
                                Age = profile.age,
                                Math = score.math,
                                English = score.english
                            };

            foreach (var student in Students2)
                Console.WriteLine(student);
        }
    }

    // Algorithm
    class Algorithm :  Practice
    {
        public override void Example()
        {
            Combination c = new Combination(5, 3);

            while(c != null)
            {
                Console.WriteLine(c.ToString());
                c = c.Successor();
            }

            Console.WriteLine();

            string[] items = new string[] { "ant", "bug", "cat", "dog", "elk" };
            c = new Combination(items.Length, 3); // 5개중 3개 조합

            string[] snapshot = null;

            while(c != null)
            {
                snapshot = c.ApplyTo(items);
                Console.Write("{ ");
                foreach (string s in snapshot)
                {
                    Console.Write(s + " ");
                }
                Console.WriteLine("}");

                c = c.Successor();
            }

            Console.WriteLine();
            
            string[] items2 = new string[] { "apple", "banana", "cherry" };
            Permutation p = new Permutation(items2.Length);
            
            while(p != null)
            {
                snapshot = p.ApplyTo(items2);
                Console.Write("{ ");
                foreach (string s in snapshot)
                {
                    Console.Write(s + " ");
                }
                Console.WriteLine("}");

                p = p.Successor();
            }
        }

        // Combiantaion
        class Combination
        {
            private long n = 0;
            private long k = 0;
            private long[] data = null;

            public Combination(long n, long k)
            {
                if(n < 0 || k < 0)
                {
                    throw new Exception("Negative parameter in constructor");
                }

                this.n = n;
                this.k = k;
                this.data = new long[k];

                for(long i =0; i <k; i++)
                {
                    this.data[i] = i;
                }
            }

            public Combination Successor()
            {
                if (this.data.Length == 0 || this.data[0] == this.n - this.k)
                {
                    return null;
                }

                Combination answer = new Combination(this.n, this.k);

                long i;
                for(i = 0; i < this.k; i++)
                {
                    answer.data[i] = this.data[i];
                }

                for (i = this.k - 1; i > 0 && answer.data[i] == this.n - this.k + i; i--) ;

                answer.data[i]++;

                for(long j = i; j < this.k-1; j++)
                {
                    answer.data[j + 1] = answer.data[j] + 1;
                }

                return answer;
            }

            public string[] ApplyTo(string[] strarr)
            {
                if(strarr.Length != this.n)
                {
                    throw new Exception("Bad array size");
                }

                string[] result = new string[this.k];

                for(long i=0; i<result.Length; i++)
                {
                    result[i] = strarr[this.data[i]];
                }

                return result;
            }

            public static long Choose(long n, long k)
            {
                if(n < 0 || k < 0)
                {
                    throw new Exception("Invalid negative parameter in Choose()");
                }

                if (n < k)
                    return 0;

                if (n == k)
                    return 1;

                long delta, iMax;

                if (k < n - k)
                {
                    delta = n - k;
                    iMax = k;
                }
                else
                {
                    delta = k;
                    iMax = n - k;
                }

                long answer = delta + 1;

                for (long i = 2; i <= iMax; i++)
                {
                    checked { answer = (answer * (delta + i)) / i; }
                }

                return answer;
            }

            public override string ToString()
            {
                StringBuilder sb = new StringBuilder();

                sb.Append("{ ");

                for(long i = 0; i < this.k; i++)
                {
                    sb.AppendFormat("{0} ", this.data[i]);
                }

                sb.Append("}");

                return sb.ToString();
            }
        }

        // Permutation
        class Permutation
        {
            private int[] data = null;
            private int order = 0;

            public Permutation(int n)
            {
                this.data = new int[n];
                for (int i = 0; i < n; i++)
                    this.data[i] = i;
                this.order = n;
            }

            public Permutation Successor()
            {
                Permutation result = new Permutation(this.order);

                int left, right;
                for(int k=0; k<result.order; k++)
                {
                    result.data[k] = this.data[k];
                }

                left = result.order - 2; 
                while((result.data[left] > result.data[left+1]) && (left >= 1))
                {
                    --left;
                }

                if((left == 0) && (this.data[left] > this.data[left+1]))
                {
                    return null;
                }

                right = result.order - 1;
                while(result.data[left] > result.data[right])
                {
                    --right;
                }

                int temp = result.data[left];
                result.data[left] = result.data[right];
                result.data[right] = temp;

                int i = left + 1;
                int j = result.order - 1;

                while(i < j)
                {
                    temp = result.data[i];
                    result.data[i++] = result.data[j];
                    result.data[j--] = temp;
                }

                return result;
            }

            internal static long Choose(int length)
            {
                long answer = 1;

                for(int i=1; i<=length; i++)
                {
                    checked { answer = answer * i; }
                }

                return answer;
            }

            public string[] ApplyTo(string[] arr)
            {
                if (arr.Length != this.order)
                    return null;

                string[] result = new string[arr.Length];
                for (int i = 0; i < result.Length; i++)
                    result[i] = arr[this.data[i]];

                return result;
            }

            public override string ToString()
            {
                StringBuilder sb = new StringBuilder();

                sb.Append("( ");
                for (int i = 0; i < this.order; i++)
                    sb.Append(this.data[i].ToString() + " ");
                sb.Append(")");

                return sb.ToString();
            }
        }
    }

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

            Practice practice;
            practice = new Yield();
            practice = new Collection();
            practice = new Delegate();
            practice = new Anonymous();
            practice = new LamdaExpression();
            practice = new FuncAction();
            practice = new Linq();
            practice = new Algorithm();
            practice.Example();
        }
    }
}
