while True:
    try:
        n = int(input())
        fract = 1
        for i in range(1,n+1):
            fract *= i
        ans = 0
        while(fract!=0):
            ans+=fract%10
            fract//=10
        print(ans)
    except EOFError:
        break
