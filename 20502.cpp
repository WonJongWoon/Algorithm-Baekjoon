//
// Created by JongWoon on 2021-05-15.
//
// Link : https://www.acmicpc.net/problem/20502

#include <bits/stdc++.h>

using namespace std;

struct Article {
    int id;
    int rank;
    unordered_set<int> keywords;

    bool operator< (const Article &rhs) const {
        return this->rank < rhs.rank;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, Q;
    cin >> N >> M;
    vector<Article> articles(N);

    for (int i = 0; i < N; i++) {
        articles[i].id = i + 1;
        cin >> articles[i].rank;
    }

    for (int i = 0, num_of_keywords; i < N; i++) {
        cin >> num_of_keywords;
        for (int j = 0, keyword; j < num_of_keywords; j++) {
            cin >> keyword;
            articles[i].keywords.insert(keyword);
        }
    }

    sort(articles.begin(), articles.end());

    cin >> Q;

    for (int i = 0, k; i < Q; i++) {
        cin >> k;
        bool is_exist = false;
        for (const Article &article : articles) {
            if (article.keywords.count(k))  { is_exist = true; cout << article.id << " "; }
        }

        if (!is_exist) cout << -1;
        cout << '\n';
    }

    return 0;
}

