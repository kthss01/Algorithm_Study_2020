# Equalize the Array
'''
    숫자로 이루어진 배열이 있는데 최소한의 제거로 같은 숫자만 남게 만들기
    ex)
    1 2 2 3
    1, 3 제거 -> 2

    1 <= n <= 100
    1 <= arr[i] <= 100
'''

def equalizeArray(arr):
    s = set(arr)

    maxCnt = 0
    
    ans = 0

    for e in s:
        if arr.count(e) > maxCnt:
            maxCnt = arr.count(e)
            maxCha = e

    for e in s:
        if e == maxCha:
            continue
        while arr.count(e) != 0:
            arr.remove(e)
            ans += 1

    return ans

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().rstrip().split()))

    result = equalizeArray(arr)
    print(result)