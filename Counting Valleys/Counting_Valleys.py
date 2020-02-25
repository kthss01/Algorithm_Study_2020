# Counting Valleys
'''
    avid 열렬한    
    meticulously 꼼꼼하게
    topography 지형

    하이킹 할 때 업힐 다운힐을 배열로 표시했음
    계곡을 몇번 지나가는지 갯수 세기

    2 <= n <= 10^6
    s[i] {U D}
'''

def countingValleys(n, s):
    altitude = 0
    isValley = False
    count = 0

    for i in range(n):
        if s[i] == 'U':
            altitude += 1
            if altitude == 0 and isValley == True:
                isValley = False
                count += 1
        else:
            if altitude == 0 and isValley == False:
                isValley = True
            altitude -= 1

    return count

if __name__ == '__main__':
    n = int(input())
    s = input()

    result = countingValleys(n,s)

    print(result)