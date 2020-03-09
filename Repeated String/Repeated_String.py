# Repeated String
"""
    문자열을 반복하게 되는데 a가 몇번 나오게 되는지 구하기

    ex)
    abcac -> n = 10
    abcacabcac -> a = 4 -> 4

    1 < |s| <= 100
    1 <= n <= 10^12
    25% test cases, n <= 10^6
"""

def repeatedString(s, n):
    ans = n // len(s) * s.count('a')

    if n % len(s) != 0:
        l = n % len(s)
        ans += (s[:l]).count('a')

    return ans

if __name__ == '__main__':
    s = input()
    n = int(input())

    result = repeatedString(s,n)
    print(result)