# Electronics Shop
'''
    keyboard 랑 usb drive 사려는데 예산에 맞춰서 사려고함
    
    가능한 최대 예산 찾기
    사는거 자체가 불가능하면 -1

    1 <= n, m <= 1000
    1 <= b <= 10^6
'''

def getMoneySpent(keyboards, drives, b):
    sum = -1

    for keyboard in keyboards:
        for drive in drives:
            if keyboard + drive <= b and keyboard + drive > sum:
                sum = keyboard + drive
                
    return sum

if __name__ == '__main__':
    
    bnm = input().split()

    b = int(bnm[0])
    n = int(bnm[1])
    m = int(bnm[2])

    keyboards = list(map(int, input().rstrip().split()))
    drives = list(map(int, input().rstrip().split()))

    result = getMoneySpent(keyboards, drives, b)

    print(result)
