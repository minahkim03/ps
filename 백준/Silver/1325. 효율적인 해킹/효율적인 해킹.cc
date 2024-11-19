#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v(10001);
int arr[10001] = {0,}, visited[10001] = {0, }, cnt = 0, maxcnt=0;

void dfs(int x) {
    cnt ++;
    visited[x] = 1;
    for(int i=0; i<v[x].size(); i++){
        int y = v[x][i];
        if(!visited[y])
            dfs(y);
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
        v[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        cnt = 0;
        for(int i=1; i<=n; i++)
            visited[i] = 0;
        dfs(i);
        arr[i] = cnt;
        if(maxcnt<cnt)
            maxcnt = cnt;
    }
    for(int i=1; i<=n; i++){
        if(arr[i]==maxcnt)
            cout << i << ' ';
    }
}