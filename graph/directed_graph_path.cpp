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
vector<edge> g[N];
priority_queue< node,vector<node> , greater<node>>Q;
long long dist[2][N];
long long path[N];



void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
    }
    Q.push({0, 1});// weight , node 

    while(!Q.empty()){
        int node = get<1> (Q.top());
        long long int w = get<0> (Q.top());

        Q.pop();

        path[node]++;
        if(node == n){
            cout<<w<<" ";
            if(path[node] == k){
                return;
            }
        }
        if(path[node]<=k){
            for(auto it : g[node]){
            int v = it.first;
            long long int d = it.second;

            Q.push({w+d,v});
        }
        }
        
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




