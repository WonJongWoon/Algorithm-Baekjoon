//
// Created by JongWoon on 2021-06-26.
//
// Link : https://www.acmicpc.net/problem/17472

#include <bits/stdc++.h>

struct edge {
    int start;
    int end;
    int weight;

    edge(int s, int e, int w) : start(s), end(e), weight(w) {}
    bool operator<(const edge rhs) const {
        return weight < rhs.weight;
    }
};

using namespace std;
using pii = pair<int, int>;

#define x first
#define y second
#define SIZE (10+1)
#define INF (987654321)
#define ISLAND_SIZE (6+1)
#define MIN_WEIGHT 2

int N, M;
int board[SIZE][SIZE];
int visited[SIZE][SIZE];
int weight[ISLAND_SIZE][ISLAND_SIZE];

int num_of_island = 0;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };


struct dsu {
    vector<int> parent;

    explicit dsu(int n) : parent(n, 0) { iota(parent.begin(), parent.end(), 0);}
    int find(int x) { return (parent[x] == x) ? x : (parent[x] = find(parent[x])); }
    bool connect(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        parent[y] = x;
        return true;
    }
};

void bfs(int cx, int cy) {
    queue<pii> Q;
    Q.emplace(make_pair(cx, cy));
    visited[cx][cy] = ++num_of_island;

    while(!Q.empty()) {
        pii cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir]; int ny = cur.y + dy[dir];
            if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
            if (visited[nx][ny] || board[nx][ny] != 1) continue;
            visited[nx][ny] = visited[cx][cy];
            Q.emplace(make_pair(nx, ny));
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    fill_n(&weight[0][0], 49, INF);

    queue<pii> q;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) q.emplace(make_pair(i, j));
        }
    }

    // calculate num of islands
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        if (visited[cur.x][cur.y]) continue;
        bfs(cur.x, cur.y);
    }

    // calculate weight between island and island
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            int si = visited[i][j];
            if (visited[i][j] == 0) continue;

            if (j+1 <= M && visited[i][j+1] == 0) { // 옆으로 측정
                for(int k = 1; j+k <= M; k++) {
                    if (visited[i][j+k] == 0) continue;
                    if (k > MIN_WEIGHT) {
                        int ei = visited[i][j + k];
                        weight[si][ei] = min(weight[si][ei], k - 1);
                    }
                    break;
                }
            }
            if (i+1 <= N && visited[i+1][j] == 0) { // 밑으로 측정
                for(int k = 1; i+k <= N; k++) {
                    if (visited[i+k][j] == 0) continue;
                    if (k > MIN_WEIGHT) {
                        int ei = visited[i + k][j];
                        weight[si][ei] = min(weight[si][ei], k - 1);
                    }
                    break;
                }
            }
        }
    }

    // minimum spanning tree construct
    dsu d(num_of_island + 1);
    vector<edge> spanning;

    for(int i = 1; i <= num_of_island; i++) {
        for(int j = 1; j <= num_of_island; j++) {
            if (weight[i][j] == INF) continue;
            spanning.emplace_back(i, j, weight[i][j]);
        }
    }

    sort(spanning.begin(), spanning.end());
    int ans = 0, bridges = 0;

    for(auto & edge : spanning) {
        if (d.connect(edge.start, edge.end)) {
            ans += edge.weight;
            bridges++;
        }
    }

    cout << ((bridges == num_of_island - 1) ? ans : - 1);

    return 0;
}
