//
// Created by JongWoon on 2021-07-16.
//
// Link : https://www.acmicpc.net/problem/1810

#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;
using pii = pair<int, int>;
using pid = pair<int, double>;
using pdi = pair<double, int>;

int N, F, f, s;
const int SIZE = 50000+2;
const int INF = 987654321;

vector<pii> v;
vector<pid> g[SIZE];

bool is_jumping(pii p1, pii p2) {
    return abs(p1.x - p2.x) <=2 && abs(p1.y - p2.y) <= 2;
}

double calc_distance(pii p1, pii p2) {
    return sqrt((int)pow(p1.x - p2.x, 2) + (int)pow(p1.y - p2.y,2));
}

vector<double> dijkstra(int start) {
    vector<double> d(N+1, INF);
    priority_queue<pdi, vector<pdi>, greater<>> q;

    q.emplace(0, start);
    d[start] = 0;

    while (!q.empty()) {
        pdi cur = q.top(); q.pop();
        double now_d = cur.x;
        int now = cur.y;
        if (d[now] != now_d) continue;

        for (pid next : g[now]) {
            int nxt = next.x;
            double nxt_d = now_d + next.y;
            if (nxt_d < d[nxt] && v[nxt].y <= F) {
                d[nxt] = nxt_d;
                q.emplace(nxt_d, nxt);
            }
        }
    }

    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> F;
    v.resize(N+1);

    for(int i = 1; i <= N; i++) {
        cin >> f >> s;
        v[i] = { f, s };
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < N; i++) {
        auto idx = distance(v.begin() + i + 1, upper_bound(v.begin() + i + 1, v.end(), make_pair(v[i].x + 3, numeric_limits<int>::min())));
        for(int k = i + 1; k < i + 1 + idx; k++) {
            if (is_jumping(v[i], v[k])) {
                double len = calc_distance(v[i], v[k]);
                g[i].emplace_back(k, len);
                g[k].emplace_back(i, len);
            }
        }
    }

    double ans = INF;

    vector<double> ret = dijkstra(0);
    for(int i = 1; i <= N; i++) {
        if (v[i].y == F) {
            ans = min(ans, ret[i]);
        }
    }

    cout << (ans >= INF ? -1 : round(ans));
    return 0;
}
