from functools import cmp_to_key
ans = ""
num = ""
def compare(x,y):    
    return int(x+y) - int(y+x)

while(round!=0):
    ans = ""
    num = ""
    round = int(input())
    if(round==0):
        break
    num = input().split(" ")
    num.sort(key=cmp_to_key(compare),reverse=True)
    
    for item in num:
        ans += item
    print(ans)  
