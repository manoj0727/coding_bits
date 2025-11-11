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
long long int vis[N];
int start;

int finish;


void dfs(int n){
    vis[n] = 1;
    for(auto it : g[n]){
        if(vis[it] == 0){
            path[it] = n;
            dfs(it);
            if(start) return;
        }
        else{
            if(vis[it]==1){
                start =it;
                finish = n;
                return;
            }
        }

    }
    vis[n] = 2;

}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    for(int i=1;i<=n && !start ;i++){
       if(vis[i]==0) dfs(i);
    }

    if(!start){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    vector<int> ans;
    ans.push_back(start);
    for(int i = finish; i!= start ; i=path[i]){
            ans.push_back(i);

    }
    ans.push_back(start);
    cout<<ans.size()<<endl;
    reverse(ans.begin(),ans.end());
    for(auto it : ans){
        cout<<it<<" ";
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




