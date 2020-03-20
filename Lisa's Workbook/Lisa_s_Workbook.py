# Lisa's Workbook
'''
    문제집이 규칙에 따라 페이지와 문제를 가지고 있음

    n쳅터가 있음 (1부터 n까지)
    i번째 쳅터는 arr[i] 문제를 가지고 있음 (1부터 arr[i]까지)
    각각의 페이지는 k 문제를 가지고 있을 수 있고 마지막 쳅터만 그보다 적은 문제를 갖음
    매 새 쳅터는 새 페이지로 시작함
    따라서 한 페이지는 한 쳅터보다 많은 문제를 가질 수 없음
    페이지는 1부터 시작

    스페셜 문제는 페이지 번호랑 문제 번호가 같은거
    몇개의 스페셜 문제를 갖는지 구하기

    ex)
    arr[1] = 4
    arr[2] = 2
    k = 3

    1쳅터 3 문제
    문제 1 페이지 1 -> 스페셜 문제
    1쳅터는 페이지 2까지 (4이므로)
    2쳅터는 페이지 3부터
    3부터인데 문제2이므로 스페셜 문제 없음
    => 1

    1 <= n,k,arr[i] <= 100
'''

import math

def workbook(n, k, arr):
    sp = 0
    page = 0

    for i in range(n):
        s = 1
        e = k
        if arr[i] < k:
            e = arr[i]
        for _ in range(math.ceil(arr[i]/k)):
            page += 1
            if page >= s and page <= e:
                sp += 1
            s += k
            e += k
            if e > arr[i]:
                e = arr[i]

    return sp

if __name__ == '__main__':
    nk = input().split()
    n = int(nk[0])
    k = int(nk[1])

    arr = list(map(int, input().rstrip().split()))

    result = workbook(n,k,arr)
    print(result)
