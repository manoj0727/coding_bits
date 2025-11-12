#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 10;


typedef pair<int,long long > edge;
typedef pair<long long ,int> node;
long long int dp[N];
struct Edge{
    int a,b;
    long long int c;
}edges[N];


vector<edge> G[N];
vector<int> g[N];
priority_queue< node,vector<node> , greater<node>>Q;
long long dist[2][N];
long long path[N];
long long path1[N];
long long int vis[N];
int start;
long long int indegree[N];
queue<int> q;
int finish;
vector<int> ans;
// int par = -1;,
void dfs(int u,int par = 0){
    vis[u] =1;
    for(auto it : g[u]){
        if(vis[it] ==0 && it!=par ){
            dfs(it,u);
        }
    }
}

void solve() {
    
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        indegree[b]++;
    }

    dfs(1);
    if(!vis[n]) {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    fill(dp+2,dp+N,-1);
    for(int i=1;i<=n;i++){

        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int val = q.front();
        q.pop();
        for(auto it :g[val]){
            if(dp[val] != -1 && dp[it]< dp[val]+1){
                dp[it] = dp[val]+1;
                path[it] = val; 
            }
            indegree[it]--;
            if(indegree[it] ==0){
                q.push(it);
            }
        }

    }

    int val = dp[n]-dp[1];
    cout<<val+1<<endl;
    for(int i=val,u=n;i>=0;i--){
        path1[i] = u;
        u = path[u];

    }
    for(int i=0;i<=val;i++){
        cout<<path1[i]<<" ";
    }
    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    // cin>>t;
    t=1;
    while(t--){
        solve();
    }
    
    return 0;
}




