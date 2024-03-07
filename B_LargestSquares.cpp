# include <bits/stdc++.h>
using namespace std;

char o[101][101];
int m,n,num;

int main(){
    int round = 0;
    while(cin>>round){
        for(int i = 0;i<round;i++){
            cin >> m >> n >> num;
            cout << m << " " << n << " " << num << endl;
           // Initialize the array
            for(int i = 0;i<101;i++){
                for(int j = 0;j<101;j++){
                    o[i][j] = 'c';
                }
            }
            // Read the input
            for(int i = 0;i<m;i++){
                for(int j = 0;j<n;j++){
                    cin >> o[i][j];
                }
            }

            // solve and print output
            for(int i = 0;i<num;i++){
                int x,y;
                cin >> x >> y;
                int half = 1;

                for(half = 1;half<=min(m,n);half++){
                    bool flag = true;
                    for(int j = x-half;j<=x+half;j++){
                        for(int k = y-half;k<=y+half;k++){
                            if(j<0 || j>=m || k<0 || k>=n){
                                flag = false;
                                break;
                            }
                            if(o[j][k] != o[x][y]){
                                flag = false;
                                break;
                            }
                        }
                        if(!flag) break;
                    }
                    if(!flag) break;
                }

                cout << 2*half-1 << endl;
            }
        }
    }
}
