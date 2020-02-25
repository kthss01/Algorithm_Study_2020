# Cats and a Mouse
"""
    고양이 2마리랑 쥐 1마리 있을 때
    어떤 고양이가 쥐를 잡을지 찾기
    같은 시간에 도착하면 쥐는 산다고함

    1 <= q <= 100 (query)
    1 <= x,y,z <= 100

    q
    x y z
    ...
"""

def catAndMouse(x,y,z):
   xz = abs(x-z)
   yz = abs(y-z)

   if xz == yz:
       return "Mouse C"
   elif xz > yz:
       return "Cat B"
   else:
       return "Cat A"

if __name__ == '__main__':

    q = int(input())

    for i in range(q):
        xyz = input().split()
        x = int(xyz[0])
        y = int(xyz[1])
        z = int(xyz[2])

        result = catAndMouse(x,y,z)

        print(result)