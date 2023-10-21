stair = [0,1,2]

def stairs():
    for i in range(3,101):
        stair.append(stair[i-1]+stair[i-2])

if __name__ == '__main__':
    stairs()
    while True:
        n = int(input())
        print(stair[n])

```
因為測資介於1-100會overflow，建議用python 寫大數的題目，為什麼我考試的時候那麼笨哈
#include <bits/stdc++.h>

using namespace std;

int main(){
    unsigned long long stair[101];
    stair[0] = 0;
    stair[1] = 1;
    stair[2] = 2;
    for(int i = 3;i<101;i++){
        stair[i] = stair[i-1] + stair[i-2];
    }
    int n;
    while(cin >> n){
        cout << stair[n] << endl;
    }
    
}
```
