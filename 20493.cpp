//
// Created by JongWoon on 2021-05-15.
//
// Link : https://www.acmicpc.net/problem/20493

#include <bits/stdc++.h>

using namespace std;

using ppi = pair<int, int>;
#define x first
#define y second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T;
    ppi current(0, 0), dir(1, 0);
    int prev_t = 0, dt = 0;

    cin >> N >> T;

    while(N--) {
        int t; string direction;
        cin >> t >> direction;
        dt = t - prev_t; prev_t = t;
        current = make_pair(current.x + (dir.x * dt), current.y + (dir.y * dt));
        dir = direction == "right" ? make_pair(dir.y, -dir.x) : make_pair(-dir.y, dir.x);
    }

    if (prev_t < T) {
        dt = T - prev_t;
        current = make_pair(current.x + (dir.x * dt), current.y + (dir.y * dt));
    }

    cout << current.x << " " << current.y << "\n";
    return 0;
}