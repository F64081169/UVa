while True:   
    try:
        B = int(input())
        P = int(input())
        M = int(input())
        input()
        ans = pow(B, P, M)
        print(ans)
    except EOFError:
        ans = pow(B, P, M)
        print(ans)
        break
