//
// Created by JongWoon on 2021-05-27.
//
// Link : https://www.acmicpc.net/problem/2487

#include <bits/stdc++.h>

using namespace std;

int N;
map<int, int> pos; // key : index, value : pos

int gcd(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b; b = r;
    }
    return a;
}

int lcm(int a, int b){
    return a * (b / gcd(a,b));
}

struct dsu {
    vector<int> parent;
    vector<int> size;

    explicit dsu(int n) : parent(n, 0), size(n, 1) { iota(parent.begin(), parent.end(), 0);}
    int find(int x) { return (parent[x] == x) ? x : (parent[x] = find(parent[x])); }
    bool connect(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;

        if (size[x] > size[y]) {
            parent[y] = x;
            size[x] += size[y];
        } else {
            parent[x] = y;
            size[y] += size[x];
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    dsu d(N+1);

    for(int i = 1, v; i <= N; i++) {
        cin >> v; pos[v] = i;
    }

    int answer = 1;

    for(auto it = pos.begin(); it != pos.end(); ++it) {
        int start = it->first;
        while (true) {
            int next = pos[start];
            if (!d.connect(start, next)) break;
            start = next;
        }
    }

    for(int i = 1; i <= N; i++) if (d.parent[i] == i) answer = lcm(answer, d.size[i]);
    cout << answer << '\n';
    return 0;
}
