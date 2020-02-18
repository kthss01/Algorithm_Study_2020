
#내장함수 map
'''
    map(f, iterable)은 함수(f)와 반복 가능한(iterable) 자료형을 입력으로 받음
    map은 입력받은 자료형의 각 요소를 함수 f가 수행한 결과를 묶어서 돌려주는 함수
'''

def two_times(x):
    return x*2

a = list(map(two_times, [1,2,3,4]))
print(a)