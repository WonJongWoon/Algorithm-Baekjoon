//
// Created by JongWoon on 2021-07-15.
//
// Link : https://www.acmicpc.net/problem/

#include <bits/stdc++.h>
#define SIZE (200000+2)
#define INF 987654321
#define x first
#define y second
#define CHANGE_DISTANCE int(1e6)

using namespace std;
using pii = pair<int, int>;

int N, L, S, E; // N : 역의 수, L 노선의 수, S : 출발지, E : 목적지

vector<pii> g[SIZE];
int routes[SIZE];
int d[SIZE];

void dijkstra(int s) {
    priority_queue<pii, vector<pii>, greater<>> q;

    fill(d, d + SIZE, INF);
    q.emplace(0, s);
    d[s] = 0;

    while (!q.empty()) {
        pii cur = q.top(); q.pop();
        int now_d = cur.x, now = cur.y;
        if (d[now] != now_d) continue;

        for (pii next : g[now]) {
            int nxt = next.x, nxt_d = now_d + next.y;
            if (nxt_d < d[nxt]) {
                d[nxt] = nxt_d;
                q.emplace(nxt_d, nxt);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> L;
    for(int i = 1; i <= L; i++) {
        int prev, next;
        cin >> prev;

        int copy_v;
        if (routes[prev] != 0) { // 정점 prev는 이미 다른 노선의 경유지인데 또 경로에 존재 -> 정점 prev 는 환승역
            copy_v = ++N; // 환승역을 중복되는 역의 번호 + 1로 카피
            g[prev].emplace_back(copy_v, CHANGE_DISTANCE); // 중복되는 점과 카피된 환승역 연결
            g[copy_v].emplace_back(prev, CHANGE_DISTANCE); // 중복되는 점과 카피된 환승역 연결
            prev = copy_v;
        }
        routes[prev] = i;

        while(true) {
            cin >> next;
            if (next == -1) break;

            if (routes[next] != 0) { // 정점 next 는 이미 다른 노선의 경유지인데 또 경로에 존재 -> 정점 next 는 환승역
                copy_v = ++N; // 환승역을 중복되는 역의 번호 + 1로 카피
                g[next].emplace_back(copy_v, CHANGE_DISTANCE); // 중복되는 점과 카피된 환승역 연결
                g[copy_v].emplace_back(next, CHANGE_DISTANCE); // 중복되는 점과 카피된 환승역 연결
                next = copy_v;
            }
            routes[next] = i;

            g[prev].emplace_back(next, 0);
            g[next].emplace_back(prev, 0);
            prev = next;
        }
    }

    cin >> S >> E;

    dijkstra(S);
    int distance = d[E];
    int ans = distance >= INF ? -1 : (distance / CHANGE_DISTANCE);
    cout << ans;


    return 0;
}
