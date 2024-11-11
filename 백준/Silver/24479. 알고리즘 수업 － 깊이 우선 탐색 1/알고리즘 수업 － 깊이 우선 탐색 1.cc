#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v(100001);
vector<bool> visited(100001);
vector<int> result(100001);
int cnt = 0;

void dfs(int x) {
    if(visited[x])
        return;
    visited[x] = 1;
    cnt ++;
    result[x] = cnt;
    
    for(int i=0; i<v[x].size(); i++)
        dfs(v[x][i]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, r;
    cin >> n >> m >> r;
    for (int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
    }
    dfs(r);
    for(int i=1; i<=n; i++)
        cout << result[i] << '\n';
}

