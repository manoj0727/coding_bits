#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int parent[N];
int sz[N];
vector<pair<int,int>> ans;

void make(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find(int v) {
    if (parent[v]<0) return v;
    return parent[v] = find(parent[v]); // Path compression
}

bool Union(int a, int b) {
    a = find(a);
    b = find(b);
    if(a==b) return false;
    if (parent[a] > parent[b])
        swap(a, b);
    parent[a] += parent[b];
    parent[b] = a;
    return true;
}

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        make(i);
        parent[i]= -1;
    }

    while (k--) {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }

    int connected_ct = 0;
    for (int i = 1; i < n; i++) {
        if (Union(i,i+1))
            ans.push_back({i,i+1});
    }
     cout << ans.size() << "\n";
    for (auto &P : ans){

        cout << P.first << " " << P.second << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
