
#내장함수 map
'''
    map(f, iterable)은 함수(f)와 반복 가능한(iterable) 자료형을 입력으로 받음
    map은 입력받은 자료형의 각 요소를 함수 f가 수행한 결과를 묶어서 돌려주는 함수
'''

def two_times(x):
    return x*2

a = list(map(two_times, [1,2,3,4]))
print(a)

# Dictionary 자료형
'''
    dic = {Key1:Value1, Key2:Value2, ...}
    
    ex)
    a = {'name':'pey', 'phone':'0110982341', 'birth':'1188'}
    a.keys() // a의 key만을 모아서 dict_keys 객체를 돌려줌

    for k in a.keys():
        print(k)

    list(a.keys())

    a.values()
    value만 얻을 수 있음

    key: value 쌍 얻으려면 items
    a.items()

    key로 value 얻기 (get)
    a.get('phone')

    해당 key가 dictionary 안에 있는지 조사하기(in)

    'name' in a
    -> True
    'email' in a
    -> False
'''

# 리스트
'''
    a = []
'''

# 튜플
'''
    리스트는 []로 둘러싸지만 튜플은 ()으로 둘러싼다
    리스트는 그 값의 생성,삭제,수정이 가능하지만 튜플은 그 값을 바꿀 수 없다

    t1 = ()
    t2 = (1,)
    t3 = (1,2,3)
'''

# 집합 Set
'''
    중복을 허용하지 않음
    순서가 없음 (Unordered)
    set자료형은 순거가 없기 때문에 인덱싱으로 값을 얻을 수 없다
    (Dictionary도 인덱싱 지원 안함)
    인덱싱으로 접근하려면 리스트나 튜플로 변환한 후 해야 함

    s1 = set([1,2,3])

    set 자료형을 유용하게 사용하는 경우는 교집합, 합집합, 차집합을 구할 때이다.

    s1 = set([1,2,3,4,5,6])
    s2 = set([4,5,6,7,8,9])

    s1 & s2 # s1.intersection(s2)와 같음 
    {4,5,6}
    s1 | s2 # s1.union(s2)
    {1,2,3,4,5,6,7,8,9}
    s1 - s2 # s1.difference(s2)
    {1,2,3}

    값 추가 add
    s1.add(4)
    여러개 추가 update
    s1.update([4,5,6])

    제거 remove
    s1.remove(2)
'''