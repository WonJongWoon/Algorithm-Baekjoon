//
// Created by JongWoon on 2021-08-14.
//
// Link : https://www.acmicpc.net/problem/1405

#include <bits/stdc++.h>

using namespace std;

const int SIZE = 30;
const int MAX = 14;

bool visited[SIZE][SIZE];

double P[4];
int N;

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
double ans;

void dfs(int x, int y, int num_of_action, double p) {
    if (num_of_action == N) { // N번 수행한 경우 확률 누적
        ans += p;
        return;
    }

    for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (x < 0 || x > 2*MAX || y < 0 || y > 2*MAX) continue; // 바깥이면 스킵
        if (visited[nx][ny]) continue; // 이미 방문한 곳이면 스킵

        visited[nx][ny] = true;
        dfs(nx, ny, num_of_action + 1, p * P[dir]);
        visited[nx][ny] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int dir = 0; dir < 4; dir++) {
        cin >> P[dir];
        P[dir] /= 100.0;
    }

    visited[14][14] = true; // 시작지점은 방문한 것으로 가정한다고 하였으므로 설정
    dfs(14, 14, 0, 1.0); // (0, 0) 을 (14, 14)로 이동하여 음의 부분을 없앤다.

    cout << fixed;
    cout.precision(11);
    cout << ans;

    return 0;
}
