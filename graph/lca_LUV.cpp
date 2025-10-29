#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9+7;
const int N = 1e5+10;
vector<int> adj[N];

int par[N];
void dfs(int v ,int p =-1){
    par[v] = p;
    for(int child :adj[v]){
        if(child==p) continue;
        dfs(child,v);
    }
}
vector<int> path(int v){
    vector<int> ans;
    while(v!=-1){
        ans.push_back(v);
        v = par[v];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
void solve() { 
    long long int n,q;
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    int x,y;
    cin>>x>>y;
    vector<int> path_x = path(x);
    vector<int> path_y = path(y);
     int mn_ln = min(path_x.size(),path_y.size());

     int lca = -1;
     for(int i=0;i<mn_ln;i++){
        if(path_x[i]==path_y[i]){
            lca = path_x[i];
        }
        else break;
     }
     cout<<lca<<endl;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    // t = 1;
    while (t--) {
        solve();
    }
    return 0;
} 