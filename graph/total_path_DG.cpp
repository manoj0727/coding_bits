#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 10;

const int mod = 1e9+7;
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
int count = 0;
// int par = -1;,
void dfs(int u,int par = 0){
    // if(vis[u] == 1 && u==n) count++;
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
    for(int i=1;i<=n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
    }
    // q.push(1);
    dp[1] = 1;
    while(!q.empty()){
        int it = q.front();

        q.pop();
        for(auto v : g[it]){
            dp[v] = (dp[v]+ dp[it])%mod;
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }
    }
    cout<<dp[n]<<endl;
    

    
    

    
    

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




