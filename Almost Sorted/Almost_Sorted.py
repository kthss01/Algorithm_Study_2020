# Almost Sorted
'''
    한번에
    두 원소를 swap하거나
    부분 원소들을 reverse해서 
    오름차순으로 정렬되는지 확인하기

    ex)
    [2,3,5,4]
    yes
    swap 3 4 (index 번호 출력)
'''

def almostSorted(arr):
    sortArr = sorted(arr)

    diffIndex = []
    diffArr = []
    for i in range(len(arr)):
        if arr[i] != sortArr[i]:
            diffIndex.append(i+1)
            diffArr.append(arr[i])

    if len(diffIndex) == 2:
        print("yes")
        print("swap %d %d" %(diffIndex[0], diffIndex[1]))
    elif len(diffIndex) > 2:
        diffArr2 = list(reversed(sorted(diffArr)))
        if diffArr == diffArr2:
            print("yes")
            print("reverse %d %d" %(diffIndex[0], diffIndex[-1]))
        else:
            print("no")
    else:
        print("no")
        
if __name__ == '__main__':
    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    almostSorted(arr)