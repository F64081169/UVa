#include <bits/stdc++.h>
using namespace std;

struct Point {
    int l, r, c;
    int step;
    Point(int l, int r, int c, int step) : l(l), r(r), c(c), step(step) {}
};

int BFS(char maze[31][31][31], int start_pos_l, int start_pos_r, int start_pos_c, int L, int R, int C) {
    queue<Point> BFS_queue;
    BFS_queue.push(Point(start_pos_l, start_pos_r, start_pos_c, 0));

    while (!BFS_queue.empty()) {
        Point current = BFS_queue.front();
        BFS_queue.pop();
        if (maze[current.l][current.r][current.c] == 'E') return current.step;
        if (maze[current.l][current.r][current.c] == '#') continue;
        maze[current.l][current.r][current.c] = '#';
        if (current.l - 1 >= 0) BFS_queue.push(Point(current.l - 1, current.r, current.c, current.step + 1));
        if (current.l + 1 < L) BFS_queue.push(Point(current.l + 1, current.r, current.c, current.step + 1));
        if (current.r - 1 >= 0) BFS_queue.push(Point(current.l, current.r - 1, current.c, current.step + 1));
        if (current.r + 1 < R) BFS_queue.push(Point(current.l, current.r + 1, current.c, current.step + 1));
        if (current.c - 1 >= 0) BFS_queue.push(Point(current.l, current.r, current.c - 1, current.step + 1));
        if (current.c + 1 < C) BFS_queue.push(Point(current.l, current.r, current.c + 1, current.step + 1));
    }
    return -1;
}

int main() {
    int L, R, C;
    char maze[31][31][31]; // 3D maze
    while (cin >> L >> R >> C) {
        if (L == 0 && R == 0 && C == 0) break;
        int start_pos_l, start_pos_r, start_pos_c;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                for (int k = 0; k < C; k++) {
                    cin >> maze[i][j][k];
                    if (maze[i][j][k] == 'S') {
                        start_pos_l = i;
                        start_pos_r = j;
                        start_pos_c = k;
                    }
                }
            }
        }

        // BFS
        int ans = BFS(maze, start_pos_l, start_pos_r, start_pos_c, L, R, C);
        if (ans == -1)
            cout << "Trapped!" << endl;
        else
            cout << "Escaped in " << ans << " minute(s)." << endl;
    }
}
