//
// Created by JongWoon on 2021-06-07.
//
// Link : https://www.acmicpc.net/problem/1012

#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

#define x first
#define y second

#define SIZE (50+2)
#define K_SIZE (2500+2)

int T;
int board[SIZE][SIZE];

pii pos[K_SIZE];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int bfs(int x, int y, int width, int height) {
    queue<pii> q;

    board[x][y] = 0;
    q.emplace(x, y);

    while(!q.empty()) {
        pii cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir], ny = cur.y + dy[dir];
            if (nx < 0 || nx >= height || ny < 0 || ny >= width) continue;
            if (board[nx][ny] != 1) continue;
            board[nx][ny] = 0;
            q.emplace(nx, ny);
        }
    }
    return 1;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;
    while(T--) {
        int M, N, K;
        cin >> M >> N >> K;
        fill_n(board[0], SIZE*SIZE, 0);

        for(int i = 1; i <= K; i++) {
            cin >> pos[i].y >> pos[i].x;
            board[pos[i].x][pos[i].y] = 1;
        }

        int ans = 0;
        for(int i = 1; i <= K; i++) {
            if (board[pos[i].x][pos[i].y])
                ans += bfs(pos[i].x, pos[i].y, M, N);
        }
        cout << ans << '\n';
    }

    return 0;
}

