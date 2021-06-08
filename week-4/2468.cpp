//
// Created by JongWoon on 2021-06-08.
//
// Link : https://www.acmicpc.net/problem/2468

#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

#define SIZE (100+2)
#define x first
#define y second

int N, max_height = -1;
int board[SIZE][SIZE];
bool visited[SIZE][SIZE];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int bfs(int x, int y, int height) {
    if (visited[x][y]) return 0;

    queue<pii> q;
    visited[x][y] = true;
    q.emplace(x, y);

    while(!q.empty()) {
        pii cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir], ny = cur.y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(visited[nx][ny] || board[nx][ny] <= height) continue;
            visited[nx][ny] = true;
            q.emplace(nx, ny);
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
            max_height = max(max_height, board[i][j]);
        }
    }

    int ans = 1;

    for(int h = 1; h <= max_height; ++h) {
        int area = 0;
        fill_n(visited[0], SIZE*SIZE, false);
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if (board[i][j] > h) {
                    area += bfs(i, j, h);
                }
            }
        }
        ans = max(ans, area);
    }

    cout << ans;

    return 0;
}

