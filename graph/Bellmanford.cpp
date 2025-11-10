#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 10;


typedef pair<int,long long > edge;
typedef tuple<long long,int ,int> node;
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
void solve() {
    int n,m;
    cin>>n>>m;
    memset(dist, 0x3f, sizeof(dist));
    fill(dp+2,dp+n+1,INF);
    for(int i=0;i<m;i++){

        int a,b;

        long long c;
        cin>>a>>b>>c;
        g[a].push_back(b);
        g[b].push_back(a);
        edges[i] = {a,b,c};
    }
    
    int ptr = -1;
    for(int i=0;i<n && ptr;i++){
        ptr = 0;
        for(int j=0;j<m;j++){
            int u = edges[j].a;
            int v = edges[j].b;
            long long int w = edges[j].c;
            if(dp[v]>dp[u]+w){
                dp[v] = dp[u]+w;
                ptr = v;
                path[v] = u;
            }
        }
    }

    if(!ptr){
        cout<<"NO"<<endl;
        return;
    }

    for(int i=0;i<n;i++){
        ptr = path[ptr];
    }
    vector<int> cycle;
    for(int v = ptr;; v = path[v]){
        cycle.push_back(v);
        if(v == ptr && (int) cycle.size() > 1)
            break;
    }
    reverse(cycle.begin(), cycle.end());

    printf("YES\n");
    int K = (int) cycle.size();
    for(int i = 0; i < K; i++)
        printf("%d%c", cycle[i], (" \n")[i==K-1]);

    
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


