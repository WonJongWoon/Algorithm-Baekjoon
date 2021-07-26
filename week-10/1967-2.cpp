//
// Created by JongWoon on 2021-07-26.
//
// Link : https://www.acmicpc.net/problem/1967

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int SIZE = 10000+2;

int dp1[SIZE], dp2[SIZE];
vector<pii> g[SIZE];
int N;

int get_dp(int x) {
    if (dp2[x] != 0) return dp2[x];
    if (g[x].empty()) return 0;


    for(pii edge : g[x]) {
        dp2[x] = max(dp2[x], get_dp(edge.first) + edge.second);
    }

    return dp2[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int i = 1; i <= N-1; i++) {
        int parent, child, cost;
        cin >> parent >> child >> cost;
        g[parent].emplace_back(child, cost);
    }

    // dp2[x] : 정점 x 를 지나고 x 가 루트인 서브트리에서 가장 먼 노드까지의 거리
    get_dp(1);

    for(int i = 1; i <= N; i++) {
        vector<int> childs_cost;
        for (pii edge : g[i]) {
            childs_cost.emplace_back(dp2[edge.first] + edge.second);
        }
        sort(childs_cost.rbegin(), childs_cost.rend());
        int ret = 0;
        for(int j = 0; j < min((int)childs_cost.size(), 2); j++) ret += childs_cost[j];
        dp1[i] = ret;
    }

    int ans = *max_element(dp1 + 1, dp1 + 1 + N);
    cout << ans;
    return 0;
}