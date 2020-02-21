# Breaking the Records
'''
    시즌 점수를 기록하고 있는데 최소 최대 점수가 변경된 횟수를 구하기

    ex)
    12 24 10 24
    24때 max++
    10때 min++
    1 1

    1 <= n <= 1000
    0 <= scores[i] <= 10^8
'''

'''
    maintain 유지하다
    tabulate 표로 만들다
'''

def breakingRecords(scores):
    min = max = 0
    minScore = maxScore = scores[0]
    for score in scores:
        if score < minScore:
            minScore = score
            min += 1
        if score > maxScore:
            maxScore = score
            max += 1
            
    return list((max, min)) # [min,max] 도 됨

if __name__ == '__main__':
    n = int(input())

    scores = list(map(int, input().rstrip().split()))

    result = breakingRecords(scores)

    print(' '.join(map(str,result)))