#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

struct Edge { int v; ll w; };
struct Node {
    int id; ll dist;
    friend bool operator<(const Node &a, const Node &b){
        return a.dist > b.dist;
    }
};

vector<Edge> G[N];
ll dist[N];
priority_queue<Node> Q;

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; ll c;
        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }

    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    Q.push({1, 0});

    while(!Q.empty()){
        ll d = Q.top().dist;
        int u = Q.top().id;
        Q.pop();

        if(d > dist[u]) continue;

        for(auto e : G[u]){
            if(dist[e.v] > d + e.w){
                dist[e.v] = d + e.w;
                Q.push({e.v, dist[e.v]});
            }
        }
    }

    for(int i = 1; i <= n; i++)
        cout << dist[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
