#include <bits/stdc++.h>
using namespace std;

int largestSquareSide(const vector<string>& grid, int r, int c) {
    int M = grid.size();
    int N = grid[0].size();
    int maxSide = min(min(r + 1, c + 1), min(M - r, N - c)); 

    for (int side = maxSide; side >= 1; --side) {
        char targetChar = grid[r][c];
        bool isValid = true;

        for (int i = r - side + 1; i <= r + side - 1; ++i) {
            for (int j = c - side + 1; j <= c + side - 1; ++j) {
                if (i < 0 || i >= M || j < 0 || j >= N || grid[i][j] != targetChar) {
                    isValid = false;
                    break;
                }
            }
            if (!isValid) break;
        }
        if (isValid) return side * 2 - 1; 
    }
    return 0; 
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int M, N, Q;
        cin >> M >> N >> Q;

        vector<string> grid(M);
        for (int i = 0; i < M; ++i)
            cin >> grid[i];

        cout << M << " " << N << " " << Q << endl;
        for (int q = 0; q < Q; ++q) {
            int r, c;
            cin >> r >> c;
            cout << largestSquareSide(grid, r, c) << endl;
        }
    }

    return 0;
}
