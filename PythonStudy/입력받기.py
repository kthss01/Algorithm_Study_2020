
#일반적인 입력 받기
#a = input()
#print(a)

#number = input("숫자를 입력하세요: ")
#print(number)

#다차원 배열 입력받기

#맵을 이용해 받고 list로 만들어 추가하는 방법
n = int(input()) # row 값 col은 자동으로 짜르니 상관 없음
arr = list()
for _ in range(n):
    arr.append(list(map(int, input().split())))

for row in arr:
    print(row)