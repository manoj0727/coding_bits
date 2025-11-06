#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;

const int N = 1e5 + 10;
long long int  dist[501][501];
void solve() {
    long long int n,m,q;
    cin>>n>>m>>q;
    memset(dist,0x3f,sizeof(dist));
    for(int i=0;i<m;i++){
        int a,b;
        long long w;
        cin>>a>>b>>w;
        dist[a][b] = min(dist[a][b],w);
        dist[b][a] = min(dist[b][a],w);
    }

    for(int i=1;i<=n;i++) dist[i][i] = 0;

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    for(int i=0;i<q;i++){
       int a,b;
        cin>>a>>b;
        if(dist[a][b] >= INF) cout << -1 << "\n";
        else cout << dist[a][b] << "\n";


    }


    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
