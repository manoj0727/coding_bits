#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 10;


typedef pair<int,long long > edge;
typedef tuple<long long,int ,int> node;

vector<edge> G[N];
priority_queue< node,vector<node> , greater<node>>Q;
long long dist[2][500];

void solve() {
    int n,m;
    cin>>n>>m;
    memset(dist, 0x3f, sizeof(dist));
    for(int i=0;i<m;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        G[a].push_back({b,c});
    }
    Q.push({0,1,1});
    dist[0][1] = 0;
    dist[1][1] = 0;

    while(!Q.empty()){
         long long  d = get<0>(Q.top());
        int u = get<1>(Q.top());
        int coupen = get<2>(Q.top());

        Q.pop();
        if(dist[!coupen][u]<d) continue;

        for(edge it : G[u]){
            int v = it.first;
            long long int w = it.second;

            if(coupen){
                if(dist[0][v] > d+w){
                    dist[0][v] = d+w;
                    Q.push({d+w,v,1});
                }
                if(dist[1][v] > d+w/2){
                    dist[1][v] = d+w/2;
                    Q.push({d+w/2 , v,0});
                }
            }
            else{
                if(dist[1][v]>d+w){
                    dist[1][v] = d+w;
                    Q.push({d+w , v,0});
                }
            }
        }
    }
    printf("%lld\n", min(dist[0][n], dist[1][n]));
    
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


