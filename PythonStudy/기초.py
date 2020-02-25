# 모듈과 시작점
# __name__ 파일이름이 들어가는 변수
"""
    hello.py 파일
    print(__name__) # hello 출력

    main.py 파일
    import hello # hello 모듈을 가져옴
    print(__name__) # main 출력

    파이썬에서 import로 모듈을 가져오면 해당 스크립트 파일이 한 번 실행됨
    따라서 hello 모듈을 가져오면 hello.py안의 코드가 실행됨
    hello.py의 __name__에는 hello가 들어가고
    main.py의 __name__ 에는 __main__이 들어감
    즉, __name__은 모듈의 이름이 저장되는 변수
    import로 모듈 가져왔을 때 모듈의 이름이 들어감
    하지만 파이썬 인터프리터로 스크립트 파일을 직접 실행했을 때는 모듈의 이름이 아니라
    __main__이 들어감

    파이썬은 최초로 시작하느 스크립트 파일과 모듈의 차이가없음
    어떤 스크립트 파일이든 시작점도 될 수 있고, 모듈도 될 수 있음
    __name__ 변수를 통해 현재 스크립트 파일이 시작점인지 모듈인지 판단

    따라서 아래와 같은 방법으로 시작점일 때만 아래 코드 실행되도록 할 수 있음
"""

if __name__ == '__main__':
    print("모듈과 시작점 예제")


# 반복문
# for문
'''
    for 변수 in 리스트(또는 튜플, 문자열:
        수행할 문장1
        수행할 문장2
        ...

    ex)
        test_list = ['one', 'two', 'three']
        for i in test_list:
            print(i)

        a = [(1,2), (3,4), (5,6)]
        for (first, last) in a;
            print(first + last)

    # range 함수
    range(10) # 0부터 10미만 숫자 포함하는 개체 만들어 줌
    시작 숫자와 끝 숫자를 지정하려면 range(시작 숫자, 끝 숫자) 형태를 ㅏㅅ용
    이때 끝 숫자는 포함되지 않음
    range(1, 11)
'''
# while문
'''
    while <조건문>:
        문장1
        문장2
        문장3
        ...

    while True:
        print('Ctrl+C를 눌러야 while문 빠져나갈 수 있음')
'''

# swap
'''
    a = 3
    b = 'abc'

    a, b = b, a # 이런식으로 바꿀 수 있음
'''

