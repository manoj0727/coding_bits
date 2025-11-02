#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int parent[N];
vector<int> adj[N];
int sz[N];
vector<pair<int,int>> ans;
queue<int> q;
bool vis[N];
int dist[N];
int path[N];
bool possible;

void dfs(int x,int p = 0){
    for(auto it : adj[x]){
        if(it!=p){
            if(!vis[it]){
                dist[it] = !dist[x];
                vis[it] = true;
                dfs(it,x);
            }
            else if(dist[x] == dist[it]){
                possible = false;
                // vis[it] = true;
            }
        }
    }

}
void solve() {
    long long int n,k;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    possible = true;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i] = true;
            dfs(i);
        }
    }
    if(!possible){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        for(int i=1;i<=n;i++){
            cout<<(dist[i]? 1: 2)<<" ";
        }
        cout<<endl;
    }
    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
