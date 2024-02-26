#include <bits/stdc++.h>
using namespace std;
char a[101][101];
int visited[101][101] = {0};
int m, n;

void dfs(int i, int j) {
    visited[i][j] = 1;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int ni = i + dx;
            int nj = j + dy;
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && a[ni][nj] == '@' && visited[ni][nj] == 0) {
                dfs(ni, nj);
            }
        }
    }
}

int main() {
    while (cin >> m >> n) {
        if (m == 0 && n == 0)
            break;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                visited[i][j] = 0;
                a[i][j] = 0;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        // dfs
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == '@' && visited[i][j] == 0) {
                    dfs(i, j);
                    count++;
                }
            }
        }
        cout << count << "\n";
    }
    return 0;
}
