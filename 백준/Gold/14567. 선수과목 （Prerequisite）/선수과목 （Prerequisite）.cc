#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v(1001);
int ans[1001];

void dfs(int x, int cnt) {
    
    if(ans[x]<cnt)
        ans[x] = cnt;
    
    for(int i=0; i<v[x].size(); i++){
        int y = v[x][i];
        if(ans[y]<=cnt)
            dfs(y, cnt+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    
    for(int i=1; i<=n; i++){
        if(ans[i]==0)
            dfs(i,1);
    }
    
    for(int i=1; i<=n; i++)
        cout << ans[i] << ' ';
}