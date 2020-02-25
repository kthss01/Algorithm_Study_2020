# Sock Merchant
'''
    Sock = 양말

    배열에 양말의 색깔이 적혀있는데 짝이 몇개나 맞는지 찾기

    1 <= n <= 100
    1 <= ar[i] <= 100 0 <= i < n
'''

def sockMerchant(n, ar):
    socks = {}

    count = 0

    for ele in ar:
        if ele in socks: # socks안에 해당 color 가 있으면
            if socks[ele] == 0: # 하나도 안채웠으면 +1
                socks[ele] = 1
            else:
                socks[ele] = 0 # 하나가 있으면 짝이므로 카운터 증가 후 0으로 초기화
                count += 1
        else: # socks안에 없으면 1 추가
            socks[ele] = 1
    return count

if __name__ == '__main__':
    n = int(input())

    ar = list(map(int, input().rstrip().split()))

    result = sockMerchant(n,ar)

    print(result)