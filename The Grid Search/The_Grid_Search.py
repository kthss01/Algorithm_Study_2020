# The Grid Search
'''
    2차원 배열에서
    2차원 부분 배열이 주어질때 이 패턴이 있는지 찾아서 YES NO 출력

    ex)
    1234567890  
    0987654321  
    1111111111  
    1111111111  
    2222222222
    
    여기서
    876543  
    111111  
    111111
    -> 가운데 있으므로 YES

    1 <= t <= 5 test cases
    1 <= R,r,C,c <= 1000
    1 <= r <= R
    1 <= c <= C
'''

def gridSearch(G, P):
    pn = len(P[0])

    for g_itr in range(len(G)):
        if G[g_itr].find(P[0]) != -1:
            offsets = []
            t = G[g_itr].find(P[0])
            offsets.append(t)
            if G[g_itr].count(P[0]) > 1:
                while G[g_itr][t+1:].find(P[0]) != -1:
                    t = G[g_itr][t+1:].find(P[0]) + t + 1
                    offsets.append(t)
           
            for offset in offsets:
                bFind = True
                for p_itr in range(len(P)):
                    if g_itr + p_itr >= len(G):
                        bFind = False
                        break
                
                    if G[g_itr + p_itr][offset:offset+pn] != P[p_itr]:
                        bFind = False
                        break

                if bFind == True:
                    return "YES"

    return "NO"

if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        RC = input().split()
        R = int(RC[0])
        C = int(RC[1])
        G = []

        for _ in range(R):
            G_item = input()
            G.append(G_item)

        rc = input().split()
        r = int(rc[0])
        c = int(rc[1])
        P = []

        for _ in range(r):
            P_item = input()
            P.append(P_item)

        result = gridSearch(G, P)
        
        print(result)