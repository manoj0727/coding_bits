#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int parent[N];
vector<int> adj[N];
int sz[N];
queue<int> q;
bool vis[N];
int dist[N];
int path[N];

void solve() {
    int n ,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    q.push(1);
    vis[1] = true;
    while(!q.empty()){
        int it = q.front();
        q.pop();
        for(auto x : adj[it]){ // 2,3,4
            if(!vis[x]){ //1,0,0,0
                dist[x] = dist[it]+1; //2->1 3->1 4->1 5->2
                vis[x] = true;
                path[x] = it; //2->1 3->1 4->1 5-> 4
                q.push(x);
            }
        }
    }
    if(!vis[n]){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    int u = n;
    int ko = dist[n]; // 2
    vector<int> ans(ko+1); // 3
    for(int i=ko;i>=0;i--){
        ans[i] = u; // 1 4 5
        u = path[u]; // 4;
    }
    cout<<ko+1<<endl;
    for(int i=0;i<=ko;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
