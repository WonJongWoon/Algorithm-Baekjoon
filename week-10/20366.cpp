//
// Created by jongwoon on 21. 7. 25..
//
// Link : https://www.acmicpc.net/problem/20366

#include <bits/stdc++.h>

using namespace std;

const int SIZE = 600+2;
const int INF = int(2*1e9+1);

struct Snow {
    int a, b, height;
    Snow(int a, int b, int height) : a(a), b(b), height(height) {}
    bool operator<(const Snow& rhs) const {
        return height < rhs.height;
    }
};

int N;
int arr[SIZE];
vector<Snow> snows;
int ans = INF;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];

    for(int i = 1; i <= N - 1; i++) {
        for(int j = i + 1; j <= N; j++) {
            snows.emplace_back(i, j, arr[i] + arr[j]);
        }
    }

    sort(snows.begin(), snows.end());

    for(int i = 0; i < (int)snows.size() - 1; i++) {
        for(int j = i + 1; j < (int)snows.size(); j++) {
            if (snows[i].a == snows[j].a || snows[i].a == snows[j].b || snows[i].b == snows[j].a || snows[i].b == snows[j].b) continue;
            ans = min(ans, snows[j].height - snows[i].height);
            break;
        }
    }

    cout << ans;
    return 0;
}
