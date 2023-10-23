#include <bits/stdc++.h>

using namespace std;

char oil[101][101];
int visit[101][101];

void DFS(int i,int j,int m,int n){
    visit[i][j] = 1;

    if(j+1<n && oil[i][j+1]=='@' && !visit[i][j+1])
        DFS(i,j+1,m,n);
    if(j>0 && oil[i][j-1]=='@'&& !visit[i][j-1])
        DFS(i,j-1,m,n);
    if(i+1<m && oil[i+1][j]=='@'&& !visit[i+1][j])
        DFS(i+1,j,m,n);
    if(i>0 && oil[i-1][j]=='@'&& !visit[i-1][j])
        DFS(i-1,j,m,n);
    if(j+1<n && i+1<m && oil[i+1][j+1]=='@'&& !visit[i+1][j+1])
        DFS(i+1,j+1,m,n);
    if(j>0 && i+1<m && oil[i+1][j-1]=='@'&& !visit[i+1][j-1])
        DFS(i+1,j-1,m,n);
    if(i>0 && j+1<n && oil[i-1][j+1]=='@'&& !visit[i-1][j+1])
        DFS(i-1,j+1,m,n);
    if(j>0 && i>0 && oil[i-1][j-1]=='@'&& !visit[i-1][j-1])
        DFS(i-1,j-1,m,n);
    
}

int main(){
    int m,n;
    // input
    while(cin >> m >>n && m!=0){
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                char c;
                cin>>c;
                visit[i][j] = 0;
                oil[i][j] = c;
            }
        }

        //DFS
        int count = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(!visit[i][j] && oil[i][j]=='@'){
                    count++;
                    DFS(i,j,m,n);
                }
            }
        }
        cout << count << endl;
    }   
}
