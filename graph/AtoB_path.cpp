#include <bits/stdc++.h>
using namespace std;

char par[1000][1000];
int dista[1000][1000];
char ans[1000000];

void solve() { 
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    int sr = 0, sc = 0, er = 0, ec = 0;

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') vis[i][j] = true;
            else if (s[i][j] == 'A') sr = i, sc = j;
            else if (s[i][j] == 'B') er = i, ec = j;
        }
    }

    queue<pair<int,int>> q;
    vis[sr][sc] = true;
    q.push({sr, sc});

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && s[nx][ny] != '#') {
                vis[nx][ny] = true;
                dista[nx][ny] = dista[x][y] + 1;
                if (i == 0) par[nx][ny] = 'U';
                else if (i == 1) par[nx][ny] = 'D';
                else if (i == 2) par[nx][ny] = 'R';
                else if (i == 3) par[nx][ny] = 'L';
                q.push({nx, ny});
            }
        }
    }

    if (!vis[er][ec]) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    cout << dista[er][ec] << "\n";
    string path;
    pair<int,int> cur = {er, ec};
    while (cur.first != sr || cur.second != sc) {
        char c = par[cur.first][cur.second];
        path += c;
        if (c == 'U') cur.first++;
        else if (c == 'D') cur.first--;
        else if (c == 'R') cur.second--;
        else if (c == 'L') cur.second++;
    }
    reverse(path.begin(), path.end());
    cout << path << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
